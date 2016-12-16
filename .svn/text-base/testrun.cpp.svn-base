#include "testrun.h"

#include <QTimer>
#include <Leap.h>

#include <QMessageBox>

/*
 * emulate java acm code to have a thread pause for a certain amount of time per sequence
 * then have the code accept an input or not
 * you can increase or decrease the pause time to increase difficulty
 */

/*!
 * \brief run::run
 * \param configuration -- The settings container
 * Runs a single game of Simon
 * Makes the board based on configuration
 */
testRun::testRun(settings_container configuration)
{
    // create new board
    gb = new board(configuration);
    QMessageBox::information(gb, tr("Test Instructions"),
                             "Press 10 buttons to exit.");
    GameOverSound.setMedia(QUrl::fromLocalFile(":/sounds/lose_game.mp3"));
    if (configuration.sound_mode()) {
        GameOverSound.setVolume(50);
    }
    else {
        GameOverSound.setVolume(0);
    }

    MID_THRESH = 200; // location of vertical divider for determining upper/lower quadrants
    HOVER_THRESH = 200; // location of vertical plane for hover detect
    CLICK_THRESH = 0; // location of vertical plane for click detect

}

/*!
 * \brief run::game_loop
 * The actual playing of the Simon Game
 */
void testRun::game_loop()
{
    gb->show();
        int numPressed = 0;



            int press = 0;
            gb->clearButtons();
            do {
                gb->clearButtons();
                Leap::Frame frame = controller.frame();
                Leap::Frame previous = controller.frame(1);
                // if touchZone value has changed
                if (frame.fingers().count() != 0) {     // if there are some fingers in the frame
                    Leap::FingerList fl = frame.fingers();    // get the list of fingers
                    Leap::Finger front = fl.frontmost();      // get the frontmost finger
                    Leap::Finger past_front = previous.fingers().frontmost();      // get the past frontmost finger
                    // if zone or quadrant changes, update accordingly
                    if (customZone(front) != customZone(past_front)
                            || whichQuadrant(front) != whichQuadrant(past_front)) {
                        switch (customZone(front)) {              // check zone of current finger
                        case 0: // finger is not close enough to trigger plane
                            std::cout << "No zone: ";
                            gb->clearButtons();
                            //break;
                        case 1: // hovering over button - finger close to trigger plane
                            std::cout << "Hover: ";
                            switch (whichQuadrant(front)) {
                            case 1:
                                gb->upperLeftHover();
                                break;
                            case 2:
                                gb->upperRightHover();
                                break;
                            case 3:
                                gb->lowerLeftHover();
                                break;
                            case 4:
                                gb->lowerRightHover();
                                break;
                            default:
                                cout << "run::game_loop: Internal error!";
                                break;
                            }
                            break;
                        case 2: // button is pressed - finger has passed trigger plane
                            std::cout << "Penetration: ";
                            numPressed++;
                            switch (whichQuadrant(front)) {
                            case 1:
                                gb->upperLeftClick();
                                press = 1;
                                break;
                            case 2:
                                gb->upperRightClick();
                                press = 2;
                                break;
                            case 3:
                                gb->lowerLeftClick();
                                press = 3;
                                break;
                            case 4:
                                gb->lowerRightClick();
                                press = 4;
                                break;
                            default:
                                cout << "run::game_loop: Internal error!";
                                break;
                            }
                            break;
                        default:
                            // Handle error cases...
                            cout << "Invalid Zone code!";
                            break;
                        }
                        std::cout << front.tipPosition().toString() << std::endl;
                    }
                }
            } while (numPressed < 10);

    gb->hide();
    return;
}

/*!
 * \brief run::whichQuadrant
 * \param f -- the finger being tracked by leap
 * \return an int representing the quadrant of the finger's tip
 */
int testRun::whichQuadrant(Leap::Finger f) {
    if (f.tipPosition()[0] < 0) {
        if (f.tipPosition()[1] < MID_THRESH) {
            return 3;
        } else {
            return 1;
        }
    } else {
        if (f.tipPosition()[1] < MID_THRESH) {
            return 4;
        } else {
            return 2;
        }
    }
    return -1; // error
}

/*!
 * \brief run::customZone
 * \param f -- the finger being tracked by leap
 * \return an int representing the zone of the finger's tip
 * the zones are 0 = none, 1 = hover, 2 = click.
 */
int testRun::customZone(Leap::Finger f) {
    if (f.tipPosition()[2] < CLICK_THRESH) {
        return 2; // crossing click threshold is a button press
    } else if (f.tipPosition()[2] < HOVER_THRESH) {
        return 1; // crossing hover threshold is a hover
    } else {
        return 0; // no zone
    }
    return -1; // error
}













