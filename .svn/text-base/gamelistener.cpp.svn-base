#include "gamelistener.h"
#include "Leap.h"
#include "LeapMath.h"

/*!
 *  This objects creates a game listener that constantly reads input
 *  from the leap motion controller.
 */

using namespace Leap;

/*!
 * \brief GameListener::onInit
 * \param controller
 * Is called when the controller is initialized
 */
void GameListener::onInit(const Controller& controller) {
    std::cout << "Initialized" << std::endl;
}

/*!
 * \brief GameListener::onConnect
 * \param controller
 * Is called when teh controller is conected
 * Sets the standard gestures for the controller.
 * Allows for Screen_Tap (poke)
 */
void GameListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
    controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
    //controller.enableGesture(Gesture::TYPE_SWIPE);
}

/*!
 * \brief GameListener::onDisconnect
 * \param controller
 * Is called when the controller is discontected
 */
void GameListener::onDisconnect(const Controller& controller) {
    //Note: not dispatched when running in a debugger.
    std::cout << "Disconnected" << std::endl;
}

/*!
 * \brief GameListener::onExit
 * \param controller
 * Is called when the Controller exits
 */
void GameListener::onExit(const Controller& controller) {
    std::cout << "Exited" << std::endl;
}

/*!
 * \brief GameListener::onFrame
 * \param controller
 * Currently Empty but is called every time the leap regesters a frame
 */
void GameListener::onFrame(const Controller& controller) {

//    const Frame frame = controller.frame();

//    if (frame.fingers().count() != 0) { // if there are some fingers in the frame
//        FingerList fl = frame.fingers();
//        Finger front = fl.frontmost();
//        switch (front.touchZone()) {
//            case 0:
//                std::cout << "No zone: ";
//                break;
//            case 1:
//                std::cout << "Hover: ";
//                break;
//            case 2:
//                std::cout << "Penetration: ";
//                break;
//            default:
//                //Handle error cases...
//                break;
//        }
//        std::cout << front.tipPosition().toString() << std::endl;
//    }

//    std::cout << "Frame id: " << frame.id()
//              << ", timestamp: " << frame.timestamp()
//              << ", hands: " << frame.hands().count()
//              << ", fingers: " << frame.fingers().count()
//              << ", tools: " << frame.tools().count()
//              << ", gestures: " << frame.gestures().count() << std::endl;


    // Get gestures
//    const GestureList gestures = frame.gestures();
//    for (int g = 0; g < gestures.count(); ++g) {
//        Gesture gesture = gestures[g];

//        switch (gesture.type()) {
//        case Gesture::TYPE_SWIPE:
//        {
//            SwipeGesture swipe = gesture;
//            std::cout << "Swipe id: " << gesture.id()
//                      << ", state: " << gesture.state()
//                      << ", direction: " << swipe.direction()
//                      << ", speed: " << swipe.speed() << std::endl;

//              std::cout << "(" << swipe.position().x << ", "<<swipe.position().y<<")\n";
//            break;
//        }
//        case Gesture::TYPE_SCREEN_TAP:
//        {
//            ScreenTapGesture screentap = gesture;
//            std::cout << "Screen Tap id: " << gesture.id()
//                      << ", state: " << gesture.state()
//                      << ", position: " << screentap.position()
//                      << ", direction: " << screentap.direction()<< std::endl;

//             std::cout << "(" << screentap.position().x << ", "<<screentap.position().y<<")\n";
//            break;
//        }
//        default:
//            std::cout << "Unknown gesture type." << std::endl;
//            break;
//        }
//    }

//    if (!frame.hands().isEmpty() || !gestures.isEmpty()) {
//        std::cout << std::endl;
//    }
}

/*!
 * \brief GameListener::onFocusGained
 * \param controller
 * Is called when the controller becomes focus
 */
void GameListener::onFocusGained(const Controller& controller) {
    std::cout << "Focus Gained" << std::endl;
}

/*!
 * \brief GameListener::onFocusLost
 * \param controller
 * Is called when the Controller is no longer the focus
 */
void GameListener::onFocusLost(const Controller& controller) {
    std::cout << "Focus Lost" << std::endl;
}
