#include "officehrssim-3.cpp"


using namespace std;
char response;
void runPrompt(){
  cout << endl << "Would you like to run an office hours simulation 100 times?" << endl;
  cout << "(y/n)" << endl;
  cin >> response;

  if(response == 'y' || response == 'Y') {
    cout << "running simulation..." << endl;
    cout << endl << "results after 100 tries:" << endl;
    officeHrsSimulation();
    runPrompt();
  }
  else{
    cout<< "Good Bye!" << endl;
  }

}
int main(){

runPrompt();

  return 0;
}
