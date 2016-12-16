#include "run.h"



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
run::run(settings_container &configuration)
{
    // create new board
    gb = new board(configuration);
    filename = configuration.return_filename();
   // csv_writer* configwrite = new csv_writer(configuration);

    //QObject::connect(gb, SIGNAL(buttonPress(int)), this, SLOT(setUserInput()));

    GameOverSound.setSource(QUrl::fromLocalFile(":/sounds/fail_game"));
    if (configuration.sound_mode()) {
        GameOverSound.setVolume(.5);
    }
    else {
        GameOverSound.setVolume(0);
    }

    for (int i=0; i<5; i++) {
        demographics[i]=configuration.return_demographic(i);
    }


    srand(time(0)); //random gen based on current time
    input = ""; // users input
    numInput = 0;
    last_correct = 0;   // keeps track of how much of
    //the sequence you did correct

    sequence_size = 40;
    sequence = new int[sequence_size];

    MID_THRESH = 200; // location of vertical divider for determining upper/lower quadrants
    HOVER_THRESH = 200; // location of vertical plane for hover detect
    CLICK_THRESH = 0; // location of vertical plane for click detect
    if(configuration.return_timeout()){
    seconds = configuration.return_timeoutsec();
    cout <<"Seconds " << seconds << endl;
    }
    else{
        seconds = 1000;
    cout << "Seconds " << seconds << endl;
    }

    // pre-generate random sequence
    gen_sequence();


}

/*!
 * \brief run::print_sequence
 * \param x -- the point of the sequence that you want to display up to and including
 * Displays the sequence as clicks on the simon board
 */
void run::print_sequence(int x)
{

    //print out sequence from sequence array
    for(int i = 0; i <= x; i++)
    {
        switch (sequence[i]) {
        case 1:
            gb->upperLeftClick();
            break;
        case 2:
            gb->upperRightClick();
            break;
        case 3:
            gb->lowerLeftClick();
            break;
        case 4:
            gb->lowerRightClick();
            break;
        default:
            cout << "Illegal sequence value.";
            break;
        }
        // delay between displaying pattern to sync
        // iteration here with actions in board.cpp
        gb->delay();
    }


}

/*!
 * \brief run::gen_sequence
 * Generates a random sequence
 */
void run::gen_sequence()
{
    //fill sequence with random ints from 1 to 4
    for(int i = 0; i < sequence_size; i++)
    {
        sequence[i] = rand() % 4 + 1;
    }
}


/*!
 * \brief run::game_loop
 * The actual playing of the Simon Game
 */
void run::game_loop() 
{
    double diff = 0;
    gb->show();
    //loop through the sequence and check user inputs
    for(int x = 0; x < sequence_size; x++)
    {
        gb->delay();
        gb->delay();
        print_sequence(x);

        // iterates through user inputs
        for(int y = 0; y <= x; y++)
        {
            time(&beginTime);
            Oclock = clock();
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
                            diff = millitime();
                            if(diff > .25){ //This should eliminate the unintentional double tap
                            cout<<"\n Elapsed Time: "<< diff << " Seconds\n";
                            timeList.push_back(diff);
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
                        }
                        std::cout << front.tipPosition().toString() << std::endl;
                    }
                }

            } while (!press && seconds > difftime(time(&endTime),beginTime));


            if( press == 0 ){
                std::cout << "Game over, you timed out." <<  endl;
                fail(x);
                x += sequence_size;     // break out of x for loop
                break;                  // break out of y for loop
            }
            else if (press != sequence[y] ) { // if user input is wrong
                std::cout << "asked for: " << sequence[y] << ", got: " << press << endl;
                fail(x);
                x += sequence_size;     // break out of x for loop
                break;                  // break out of y for loop
            }

        }
    }
    gb->hide();
    return;
}

/*!
 * \brief run::whichQuadrant
 * \param f -- the finger being tracked by leap
 * \return an int representing the quadrant of the finger's tip
 */
int run::whichQuadrant(Leap::Finger f) {
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
int run::customZone(Leap::Finger f) {
    if (f.tipPosition()[2] < CLICK_THRESH) {
        return 2; // crossing click threshold is a button press
    } else if (f.tipPosition()[2] < HOVER_THRESH) {
        return 1; // crossing hover threshold is a hover
    } else {
        return 0; // no zone
    }
    return -1; // error
}

/*!
 * \brief run::fail
 * \param x -- the score of the player
 * For the end of the game;
 *  sets last_correct to the x param
 */
void run::fail(int x){
    last_correct = x;
    GameOverSound.play();
    this->writedata();
    QString gameoverstring="Game Over!\nYour score was: "+QString::number(last_correct);
    QMessageBox::information(gb, tr("Game Over"),
                             gameoverstring);

}





string run::return_demographic(int choice) {
    return demographics[choice];
}
int run::return_saved_sequence(int index) {
    return sequence[index];
}
int run::return_sequence_size() {
    return last_correct;
}
void run::writedata() {
    ofstream userwrite;
    userwrite.open(filename.c_str(),ios::app);
    userwrite<<"Demographics,";
    for (int i=0;i<5;i++) {
       userwrite<<demographics[i];
       userwrite<<",";
    }
    userwrite<<endl;
    userwrite<<"Sequence,";
    for (int i=0; i<last_correct+1; i++) {
        int seq=sequence[i];
        switch(seq) {
            case 1:
                userwrite<<"G";
                break;
            case 2:
                userwrite<<"R";
                break;
            case 3:
                userwrite<<"Y";
                break;
            case 4:
                userwrite<<"B";
                break;
        }

        userwrite<<",";
        }
        userwrite<<endl;
        userwrite<<"Time Between Clicks,";
        for (std::list<double>::iterator it=timeList.begin(); it!=timeList.end(); it++) {
            userwrite<<(*it)<<",";
        }
        userwrite<<endl;
        userwrite<<"Final Score,";
        userwrite<<last_correct;
        userwrite<<","<<endl;
}

float run::millitime(){
    clock_t end = clock()-Oclock;

    float dif = ((float)end)/CLOCKS_PER_SEC;

    return dif;

}
void run::keyboard_loop() {
    gb->show();
    //loop through the sequence and check user inputs
    for(int x = 0; x < sequence_size; x++)
    {
        gb->delay();
        gb->delay();
        print_sequence(x);

        // iterates through user inputs
        for(int y = 0; y <= x; y++)
        {
           gb->clear_key_input();
            time(&beginTime);
            Oclock = clock();
            gb->clearButtons();
            do {
                    gb->grabKeyboard();

            } while (gb->return_key_input()==0 && seconds > difftime(time(&endTime),beginTime));
            int press=gb->return_key_input();


            if( press == 0 ){
                std::cout << "Game over, you timed out." <<  endl;
                fail(x);
                x += sequence_size;     // break out of x for loop
                break;                  // break out of y for loop
            }
            else if (press != sequence[y] ) { // if user input is wrong
                std::cout << "asked for: " << sequence[y] << ", got: " << press << endl;
                fail(x);
                x += sequence_size;     // break out of x for loop
                break;                  // break out of y for loop
            }

        }
      }
    gb->hide();
    return;
}
