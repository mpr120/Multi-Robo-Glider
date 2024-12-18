//Name: Mitchell Johnson
//Date:4/5/2022
//Coding Project 3
//collabs: None
#include <iostream>
#include <cmath>
using namespace std;

class robot //class with info from robots.
{
private:
char lastCommand;
int currentSpeed;
int y;
int x;
int distance;
string name;

public:

void setXY(robot roboArr[], int SIZE){
    //method sets initial X and Y values to 0.
    //roboArr is the array of robots
    //size is the size of the array
  for (int i=0; i<SIZE; i++){
    roboArr[i].x = 0;
    roboArr[i].y = 0;
  }
}
void setDistance(robot roboArr[], int SIZE){
    //method set initial distance for robots.
        //roboArr is the array of robots
    //size is the size of the array
  for (int i=0; i<SIZE; i++){
    roboArr[i].distance = 0;
  }
}
void setSpeed(){
  currentSpeed++;
}
void resetSpeed(robot roboArr[], int valueforName){
    //method resets speed of robots.
    //roboArr is the array of robots
    //valueforName is the "spot" in the array
    //ex. roboArr[0].
    roboArr[valueforName].currentSpeed=0;
}
void setName(robot roboArr[], int SIZE){
    //method sets the name of robots.
    //roboArr is the array of robots
    //size is the size of the array
  for (int i=0; i<SIZE; i++)
    cin >> roboArr[i].name;
}
void resetName(robot roboArr[], int SIZE){
    //roboArr is the array of robots
    //size is the size of the array
    //method changes the name of a robot.
  cout << "Who would you like to rename?" << endl;
  for(int i = 0; i < SIZE; i++){
      cout << roboArr[i].getName() << endl;
  }
  string p;
  cin >> p;
  string newName;
  cout << "What should " << p << "'s new name be?" << endl;
  if(roboArr[0].name == p){
    cin >> newName;
    roboArr[0].name = newName;
  }
  if(roboArr[1].name == p){
    cin >> newName;
    roboArr[1].name = newName;
  }
  if(roboArr[2].name == p){
    cin >> newName;
    roboArr[2].name = newName;
  }
  if(roboArr[3].name == p){
    cin >> newName;
    roboArr[3].name = newName;
  }
  }


void findDistance(robot roboArr[], int SIZE){
        //roboArr is the array of robots
        //size is the size of the array
      for(int i = 0; i < SIZE; i++){
         roboArr[i].distance = sqrt(pow(roboArr[i].getDistance(), 2));
         }
         // will keep all distances positive by squaring them,
         // then taking squareroot.
         int hold, temp, j; //sorting the names and distances.
         for(int i = 0; i < SIZE; i++) {

            for( j = i+1; j < SIZE; j++)
            {                       //sort distance
                if (roboArr[j].getDistance() > roboArr[i].getDistance()){
                    temp = roboArr[i].getDistance();
                    roboArr[i].distance = roboArr[j].getDistance();
                    roboArr[j].distance = temp;

                    string hold = roboArr[i].getName(); //sort robot names
                    roboArr[i].name = roboArr[j].getName();
                    roboArr[j].name = hold;
                }
            }
         }
         for(int i = 0; i < SIZE; i++){
            cout << roboArr[i].getName() <<":   ";
            cout << roboArr[i].getDistance() << endl;
         }
}
//list of getters for privated variables.
int getcurrentSpeed(){return currentSpeed;}
int getlastCommand(){return lastCommand;}
int getDistance(){return distance;}
string getName(){return name;}
int getX(){return x;}
int getY(){return y;}

int findRobot(robot roboArr[],int SIZE, int &valueforName){
//findRobot finds the robot name that user searchs for.
//*roboArr points to roboArr passed for struct access.
//roboList passed to find individual robots.
//Size passed to loop through names.
//valueforName passed to check values of roboList for comparison.
cout << "Which robot would you like to move?" << endl;
for(int i = 0; i < SIZE; i++){
    cout << roboArr[i].getName() << endl;
}
string names;
cin >> names;
 for(int i = 0; i<SIZE; i++){
    // checks for robot name and passes value associated with name.
    if (names == roboArr[i].getName()){
      valueforName = i;
      return valueforName;
      }
 }

 valueforName = -1;//in case name fails.
 return valueforName;
    }

void moveRobot(robot roboArr[], int SIZE, int &valueforName){
  //moveRobot will move the robot based on user choice.
  //*roboArr points at roboArr, allows for changes to the struct
  //and access to info.
  // Size passed to indicate current place in arrays.
  // &d passed to change speed of robots based on last move.
  //valueforName indicates which robot is moving based on it value.
  char ch;
    cout << "Now Moving Robot, Please select : "<< endl;
    cout << "   U- Move up " << endl;
    cout << "   D- Move down" << endl;
    cout << "   R- Move right" << endl;
    cout << "   L- Move left" << endl;
    cout << "   S- Stop/Start" << endl;
    cout << "   Q- quit" << endl;
    cin >> ch;
    switch (ch){ //used for movement
     case 'U':
     case 'u':                //if true picks up speed
        if (roboArr[valueforName].lastCommand == 'u'){
            roboArr[valueforName].y++;
            //adds speed
            roboArr[valueforName].y += roboArr[valueforName].getcurrentSpeed();
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            //calculates distance, keeping numbers positive.
            roboArr[valueforName].setSpeed();

        }
        if(roboArr[valueforName].lastCommand == 's'){
            cout << "you are still stopped"<< endl;
            roboArr[valueforName].lastCommand = 'u';
            return;
            }                          // if true loses current speed(if any).
        if (roboArr[valueforName].lastCommand != 'u'){
                                // if character was changed speed reset.
            roboArr[valueforName].resetSpeed(roboArr, valueforName);
            roboArr[valueforName].y++;
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();
            roboArr[valueforName].lastCommand = 'u';
            }
        else{
        return;
        }             //sets character to start gaining speed.
        roboArr[valueforName].lastCommand = 'u';
        break;

     case 'D'://repeated steps from above for down direction.
     case 'd':

        if (roboArr[valueforName].lastCommand == 'd'){
            roboArr[valueforName].y--;
            roboArr[valueforName].y -= roboArr[valueforName].getcurrentSpeed();
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();

            }
       if(roboArr[valueforName].lastCommand == 's'){
            cout << "you are still stopped"<< endl;
            roboArr[valueforName].lastCommand = 'd';
            break;
            }
       if (roboArr[valueforName].lastCommand != 'd'){
            roboArr[valueforName].resetSpeed(roboArr, valueforName);
            roboArr[valueforName].y--;
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();
            roboArr[valueforName].lastCommand = 'd';
            }
        else{
            return;
            }
        roboArr[valueforName].lastCommand = 'd';
        break;

     case 'L'://repeated steps from above for left direction.
     case 'l':

        if (roboArr[valueforName].lastCommand == 'l'){
            roboArr[valueforName].x--;
            roboArr[valueforName].x -= roboArr[valueforName].getcurrentSpeed();
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();

            }
        if(roboArr[valueforName].lastCommand == 's'){
            cout << "you are still stopped"<< endl;
            roboArr[valueforName].lastCommand = 'l';
            return;
            break;
            }
        if(roboArr[valueforName].lastCommand != 'l'){
            roboArr[valueforName].resetSpeed(roboArr, valueforName);
            roboArr[valueforName].x--;
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();
            roboArr[valueforName].lastCommand = 'l';
            }
        else{
            return;
            }
        roboArr[valueforName].lastCommand = 'l';
        break;

     case 'R'://repeated steps from above for right direction.
     case 'r':

        if (roboArr[valueforName].lastCommand == 'r'){
            roboArr[valueforName].x++;
            roboArr[valueforName].x += roboArr[valueforName].getcurrentSpeed();
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();
            cout << roboArr[valueforName].lastCommand << endl;

            }
        if(roboArr[valueforName].lastCommand == 's'){
            cout << "you are still stopped"<< endl;
            roboArr[valueforName].lastCommand = 'r';
            return;
            }

        if(roboArr[valueforName].lastCommand != 'r'){
            roboArr[valueforName].resetSpeed(roboArr, valueforName);
            roboArr[valueforName].x++;
            cout << roboArr[valueforName].name;
            cout << "'s new position is (" <<roboArr[valueforName].x << ",";
            cout << roboArr[valueforName].y << ")"<< endl;
            roboArr[valueforName].distance++;
            roboArr[valueforName].setSpeed();
            roboArr[valueforName].lastCommand = 'r';
            }
         else{
            return;
            }
        roboArr[valueforName].lastCommand = 'r';
        break;
     case 'S':
     case 's':             //stops the robots.
        if(roboArr[valueforName].lastCommand != 's'){
            cout << "You are now stopped"<< endl;
            resetSpeed(roboArr,valueforName);
            }               ///start the robots.
        if(roboArr[valueforName].lastCommand == 's'){
            cout << "You are now started back up!"<< endl;
            roboArr[valueforName].lastCommand = 'o';
            return;
            break;
            }
        roboArr[valueforName].lastCommand = 's';
        break;

     case 'Q': //quits out of movement. sent back to "main menu".
     case 'q':
       cout << "Thanks for moving me around! Bye..." << endl;
       return;
       break;

     default:{cout<<"Error, please enter a valid";
     cout << " character so I can move!" << endl;
     return; //returns error
     }
    }

  return;


return;
}
};


robot** makeRoboList(int SIZE){
    //dynamically allocates memory for array
    //based on SIZE / user input.
  robot** roboList = new robot*[SIZE];
  for(int i = 0; i < SIZE; i++){
    roboList[i] = new robot;
  }
  return roboList;
}

int main() {
  int valueforName = -1;
  bool runProgram = true;
  string identifier;
  int SIZE = 4;
  robot roboArr[SIZE];
  roboArr[SIZE].setXY(roboArr, SIZE);
  roboArr[SIZE].setDistance(roboArr, SIZE);
  int incaseFail = -1;
  char choice;
  cout << "Welcome to MultiRobo Guider." << endl;
  cout << "Please enter the number of robots desired." << endl;
  int numRobos;
  cin >> numRobos;
  robot** roboList = makeRoboList(numRobos);
  cout << "Please enter the names of your robots." << endl;
  SIZE = numRobos;
  roboArr[SIZE].setName(roboArr, SIZE);

  SIZE = numRobos;
  cout << "Robots will move faster (more steps per action) the longer they move in one direction."<< endl;

  while (runProgram){
  cout << "Please select:" << endl;
  cout << "   M- move a robot" << endl;
  cout << "   D- distance from center" << endl;
  cout << "   R- Rename" << endl;
  cout << "   Q- quit" << endl;
    cin >> choice;
    switch (choice){
      case 'M':
      case 'm':        // calls to functions.
           roboArr->findRobot(roboArr, SIZE, valueforName);
              if(valueforName >= 0){
                roboArr[valueforName].moveRobot(roboArr, SIZE, valueforName);
                break;
    }

              if(valueforName<= -1){ //for wrong name
                cout<< "Please enter a valid name!" << endl;
                break;
    }
      break;
      case 'D':
      case 'd':  //for outputting distance robots have traveled.
       for(int i=0; i==0; i++){
       roboArr[i].findDistance(roboArr, SIZE);
         }
       break;
      case 'R':
      case 'r':
          roboArr->resetName(roboArr, SIZE);
      break;
      case 'Q':
      case 'q':  //quits program
      cout << "Bye Bye..." << endl;
      runProgram = false;  //ends loop and program.
      delete roboList; //deletes allocated memory before program quits.
      return 0;
      default: cout << "Thats not one of your options! Try again." << endl;

   }
   }

   return 0;
  }
