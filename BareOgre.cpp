#include <iostream>

#include "BareOgre.h"

#include "OgreCamera.h"
#include "OgreEntity.h"
#include "OgreException.h"
#include "OgreSceneManager.h"
#include "OgreRenderWindow.h"
#include "OgreViewport.h"
#include "OgreWindowEventUtilities.h"

#include "GL3Plus/include/OgreGL3PlusPlugin.h"

#include "OgreSceneNode.h"

#include "OgreMaterialManager.h"
#include "OgreTextureManager.h"

BareOgre::BareOgre()
    : mSlowMove(false)
    , mMovingForward(false)
    , mMovingBack(false)
    , mMovingRight(false)
    , mMovingLeft(false)
    , mMovingUp(false)
    , mMovingDown(false)
    , mPluginsCfg("")    
    , mResourcesCfg("")
    , mRoot(0)      
    , mShutdown(false)
    , mVelocityDirection(Ogre::Vector3::ZERO)
{
    // Default camera control parameters.
    mRotationSpeed = 0.13;
    mMaxSpeed = 1000;
    mSlowMaxSpeed = mMaxSpeed / 15;
    mAccelerationRate = 100;
}


BareOgre::~BareOgre()
{
    // Remove ourself as a window listener.
    // Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
    // windowClosed(mWindow);

    delete mRoot;
}


bool BareOgre::go()
{
    printf("BareOgre::go...\n");

    mLog = new Ogre::LogManager;
    //TODO: Come up with a better log name.
    mLog->createLog("ogre.log");

#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif

    mRoot = new Ogre::Root();

    printf("GL3PlusPlugin...\n");

    static Ogre::GL3PlusPlugin* plugin;
    plugin = OGRE_NEW Ogre::GL3PlusPlugin();
    mRoot->installPlugin(plugin);
    mRoot->setRenderSystem(mRoot->mRenderers[0]);

    printf("GL3PlusPlugin ok %p\n", mRoot->mActiveRenderer);
    printf("RenderSystemList %lu\n", mRoot->mRenderers.size());

    // Load resource paths from resources config file.
    setupResources();


    // Create RenderWindow.
    mWindow = mRoot->initialise(true, "BareOgre Render Window");

    // initVideo();
    // mWindow = mRoot->initialise(false);

    // struct SDL_SysWMinfo wmInfo;
    // SDL_VERSION(&wmInfo.version);

    // if (SDL_GetWindowWMInfo(mSDLWindow, &wmInfo) == SDL_FALSE)
    //     throw std::runtime_error("Couldn't get WM Info!");

    // Ogre::String winHandle;

    // switch (wmInfo.subsystem)
    // {
    // case SDL_SYSWM_X11:
    //     winHandle = Ogre::StringConverter::toString((unsigned long)wmInfo.info.x11.window);
    //     break;
    // default:
    //     throw std::runtime_error("Unexpected WM!");
    //     break;
    // }

    // Ogre::NameValuePairList params;
    // params.insert(std::make_pair("title", "OGRE Window"));
    // params.insert(std::make_pair("FSAA", "0"));
    // params.insert(std::make_pair("vsync", "false"));
    // // params.insert(std::make_pair("parentWindowHandle", winHandle));
    // params.insert(std::make_pair("externalWindowHandle", winHandle));

    // mWindow = Ogre::Root::getSingleton().createRenderWindow("OGRE Window", 640, 480, false, &params);
    // mWindow->setVisible(true);
    // mWindow->setActive(true);
    // mWindow->setAutoUpdated(false);

    // Initialize input. (SDL2)
    initInput();

    // Set default mipmap level.
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

    // Initialize all resource groups.
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

    // Create scene.
    createScene();

    // Set initial mouse clipping size.
    // windowResized(mWindow);

    // Register as a Window listener.
    // Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

    // Start render loop.
    mLog->logMessage("*** Begin Rendering ***");
    mRoot->addFrameListener(this);
    mRoot->startRendering();

    printf("BareOgre::go ok\n");

    return true;
}


void BareOgre::createScene()
{
    // Create SceneManager.
    mSceneMgr = mRoot->createSceneManager("DefaultSceneManager");

    // Create a camera.
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(0, 0, 80));
    mCamera->lookAt(Ogre::Vector3(0, 0, -3));
    mCamera->setNearClipDistance(5);
    mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode");
    mCamNode->attachObject(mCamera);

    // Create one viewport, entire window.
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

    // Set camera aspect ratio to match viewport.
    mCamera->setAspectRatio(
        Ogre::Real(vp->getActualWidth() / Ogre::Real(vp->getActualHeight())));

    // Add lighting.
    mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0, 1.0, 1.0));

    Ogre::Light* l = mSceneMgr->createLight("MainLight");
    l->setPosition((Ogre::Real)20.0, (Ogre::Real)80.0, (Ogre::Real)50.0);

    // Add meshes.
    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");
    Ogre::SceneNode* headNode =
        mSceneMgr->getRootSceneNode()->createChildSceneNode();
    headNode->attachObject(ogreHead);    
}


// void BareOgre::initInput()
// {
//     mLog->logMessage("*** Initializing OIS ***");
//     OIS::ParamList pl;
//     size_t windowHnd = 0;
//     std::ostringstream windowHndStr;

//     mWindow->getCustomAttribute("WINDOW", &windowHnd);
//     windowHndStr << windowHnd;
//     pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

//     //TODO: Remove me or integrate further.
//     bool nograb = true;
//     if (nograb)
//     {
//         pl.insert(std::make_pair("x11_keyboard_grab", "false"));
//         pl.insert(std::make_pair("x11_mouse_grab", "false"));
//         pl.insert(std::make_pair("w32_mouse", "DISCL_FOREGROUND"));
//         pl.insert(std::make_pair("w32_mouse", "DISCL_NONEXCLUSIVE"));
//         pl.insert(std::make_pair("w32_keyboard", "DISCL_FOREGROUND"));
//         pl.insert(std::make_pair("w32_keyboard", "DISCL_NONEXCLUSIVE"));
//     }


//     mInputManager = OIS::InputManager::createInputSystem(pl);
//     //TODO switch to buffered input
//     mKeyboard = static_cast<OIS::Keyboard*>(
//                                             mInputManager->createInputObject(OIS::OISKeyboard, true));
//     mMouse = static_cast<OIS::Mouse*>(
//                                       mInputManager->createInputObject(OIS::OISMouse, true));

//     mKeyboard->setEventCallback(this);
//     mMouse->setEventCallback(this);
// }


// void BareOgre::initVideo()
// {
//     mLog->logMessage("*** Initializing SDL2 Video ***");

//     // if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
//     // {
//     //     mLog->logMessage("error: SDL2 input failed to initialize!");
//     //     //TODO: error handling.
//     // }

//     // Create an application window with the following settings:
//     mSDLWindow = SDL_CreateWindow(
//                                   "An SDL2 window", // window title
//                                   SDL_WINDOWPOS_UNDEFINED, // initial x position
//                                   SDL_WINDOWPOS_UNDEFINED, // initial y position
//                                   640, // width, in pixels
//                                   480, // height, in pixels
//                                   SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED // flags - see below
//                                   );

//     // Check that the window was successfully made
//     if (mSDLWindow == NULL) {
//         // In the event that the window could not be made...
//         std::cout << "Could not create window: " << SDL_GetError() << std::endl;
//     }
// }
    

void BareOgre::initInput()
{
    mLog->logMessage("*** Initializing SDL2 Input ***");

}

    
void BareOgre::setupResources()
{
}

    
bool BareOgre::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if (mWindow->isClosed()) return false;
    if (mShutdown) return false;

    // Build our acceleration vector based on keyboard input composite.
    mAcceleration = Ogre::Vector3::ZERO;
    if (mMovingForward) mAcceleration += mCamera->getDirection();
    if (mMovingBack) mAcceleration -= mCamera->getDirection();
    if (mMovingRight) mAcceleration += mCamera->getRight();
    if (mMovingLeft) mAcceleration -= mCamera->getRight();
    if (mMovingUp) mAcceleration += mCamera->getUp();
    if (mMovingDown) mAcceleration -= mCamera->getUp();    

    // If accelerating, try to reach max speed in a certain time.
    if (mAcceleration != Ogre::Vector3::ZERO)
    {
        mAcceleration.normalise();
        mVelocity += mAccelerationRate * mAcceleration * evt.timeSinceLastFrame;
    }
    // If not accelerating, but still moving, come to a gradual stop.
    else if (mVelocity.squaredLength() > 1E-10)
    {
        mVelocity /= mAccelerationRate * evt.timeSinceLastFrame;
    }
    // If moving extremely slowly, stop.
    else
    {
        mVelocity = Ogre::Vector3::ZERO;
    }

    if (mVelocity != Ogre::Vector3::ZERO)
    {
        // Keep camera velocity below max speed and above epsilon.
        Ogre::Real maxSpeed = mSlowMove ? mSlowMaxSpeed : mMaxSpeed;
        if (mVelocity.squaredLength() > maxSpeed * maxSpeed)
        {
            mVelocity.normalise();
            mVelocity *= maxSpeed;
        }
        mCamera->move(mVelocity * evt.timeSinceLastFrame);
    }
                  
    return true;
}


// Adjust mouse clipping area.
// void BareOgre::windowResized(Ogre::RenderWindow* rw)
// {
//     unsigned int width, height, depth;
//     int left, top;
//     rw->getMetrics(width, height, depth, left, top);

//     // const OIS::MouseState &ms = mMouse->getMouseState();
//     // ms.width = width;
//     // ms.height = height;
// }


// // Unattach OIS before window shutdown (very important under Linux).
// void BareOgre::windowClosed(Ogre::RenderWindow* rw)
// {
//     SDL_Quit();
// }



