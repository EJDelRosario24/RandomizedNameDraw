#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>

//For Cleaning Before Running
void clearBeforeRunning(){
  std::cout << "\033[2J\033[1;1H";
}

// To add a delay 
void delay(int time){
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

// for Line Breaking (Optional)
void Br()
{
  using namespace std;

  cout << "\n";
}

int main()
{
  clearBeforeRunning();
  srand(time(NULL));

  bool drawStarts = false;
  std::string PutNames, showName, selection;

  //Vector Array of Namelist
  std::vector<std ::string> Names = {};

  while (drawStarts == false)
  {

//input Names
    std::cout << "\n"
              << "Enter A Name:" << std::endl;
    std::cin >> PutNames;
  getline(cin, PutNames);
    Names.push_back(PutNames);
    // i =+1;

         
    bool selectionLoop = true;
    while (selectionLoop == true)
    {               // System Menu Pannel
      std::cout << "\n"
                << "Numbers of Names stored: " << Names.size()
                << "\n"
                << "Enter (G) To Enter A Name Again.\n"
                << "Enter (V) To View The Namelist.\n"
                << "Enter (D) To Remove A Name\n"
                << "Enter (S) To Start The Draw:\n"

                << std::endl;
      std::cin >> selection;


       
                   //Draw System
      if (selection == "S" || selection == "s")
      {
        if (Names.size() > 1)
        {

          clearBeforeRunning();
          std::string showName;
          int n = Names.size();
          int Lc = 1, i = 0;

          while (i < n)
          {

            showName = Names[i];
            std::cout << Lc << ". " << showName << std::endl;
            Lc++;
            i++;

            if (i >= n)
            {
              break;
              selectionLoop = false;
            }
          }
          std::cout << "\n"
                    << std::endl;
          delay(3000);
          int RandIndex = rand() % Names.size();
          std::string TheChosen1 = Names[RandIndex];
          if (TheChosen1 == " ")
          {
            continue;
          }

          for (int v = 0; v < 30; v++)
          {
            delay(300);

            std::cout << "\n"
                      << "Choosing \"The Chosen One!\""
                      << "\n"
                      << std::endl;
            for (int j = 0; j < v; j++)
              std::cout << '#';

            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            std::cout << " " << ((float)v / 30) * 100 << "%";

            delay(300);

            clearBeforeRunning();
          }

          std::cout << "\n\n"
                    << "Congratulations, \""
                    << TheChosen1 << "\" You are \"The Chosen One!\""
                    << "\n\n\n\n"
                    << std::endl;
            delay(3000);
          drawStarts = true;
          bool EndPannelLoop=true;
          std::string endPannel;
           while(EndPannelLoop==true){
          std::cout<<"\"Refresh and reset\"(r)   \"Back\"(b)   \"Exit\"(x)\n"; 
          std::cin>>endPannel;

          if (endPannel=="r"||endPannel=="R"){
           EndPannelLoop = false;
           
            Names.clear();
           selectionLoop = true;  
           delay(3000);
          }
          
          else if (endPannel=="b"||endPannel=="B"){
          
          EndPannelLoop = false;
            selectionLoop = true;  
          delay(3000);
          }
          
          else if (endPannel=="x"||endPannel=="X"){
          EndPannelLoop = true;
            selectionLoop = false;  
          }
          else {
          EndPannelLoop=true;
            
          std::cout<<"Invalid";

            }
          }
        }






        else if (Names.size() < 2)
        {
          std::cout << " <!System Error!>"
                    << "\n Note: Name List must consist of"
                    << "\n 2 or more Names to start draw" << "\n"
                    << std::endl;
          delay(5000);
        }
      }



                 //Add Name System
      else if (selection == "G" || selection == "g")
      {
        std::cout << "\n\n";

        drawStarts = false;
        selectionLoop = false;
      }







                 //View Names/Namelist System
      else if (selection == "V" || selection == "v")
      {
        //   int size =Names.l
        // while (Names.size() > 0){

       
        int n = Names.size();
        int Lc = 1;
        int i = 0;
        std::cout << "Name List:\n"
                  << std::endl;
       if(Names.size()==0){
       std::cout<<"<!EMPTY!>\n\n"; }
       
       else{
           
        while (i < n)
        {

          std::string showName = Names[i];
          std::cout << Lc << ". " << showName << std::endl;
          Lc++;
          i++;
          if (i >= n)
          {
            break;
            selectionLoop = false;
           }
         }
           
       }
        //}
      }


             //Delete Name System
      else if (selection == "D" || selection == "d")
      {
        bool removeNamesLoop = true;
        bool keepRemoving,
            ConfirmationLoop,
            isFinishedLoop;
        while (removeNamesLoop == true)
        {
          int removeName;
          keepRemoving = 1;
          std::string Confirmation;

          int n = Names.size();
          int Lc = 1;
          int i = 0;
          std::cout << "Name List:\n"
                    << std::endl;
          while (i < n)
          {

            std::string showName = Names[i];
            std::cout << "(" << Lc << ") " << showName << std::endl;
            Lc++;
            i++;
            if (i > n)
            {
              break;
            }
          }
          std::string isFinished;
          while (keepRemoving == 1)
          {
            std::cin >> removeName;
            int removeName1 = removeName - 1;

            Lc = Lc - 1;
            ConfirmationLoop = true;
            
            // Confimation
            if(n==1||n==0){
                std::cout<<"\"A Name Have Been Successfully Removed\"";
            }
            while (ConfirmationLoop == true)
            {
              std::cout << "\nAre You sure?"
                        << "\"Y\" for yes and \"N\" for No\n"
                        << std::endl;
              std::cin >> Confirmation;

              if (Confirmation == "Y" || Confirmation == "y")
              {
                ConfirmationLoop = 0;
                Names.erase(Names.begin() + removeName1);
              }
              else if (Confirmation == "N" || Confirmation == "n")
              {

                break;
              }
              else
              {
                std::cout << "\n"
                          << "invalid response" << "\n";
                ConfirmationLoop = 1;
              }
            }

            isFinishedLoop = true;
            // Continue or remove again
            while (isFinishedLoop == true)
            {
              std::cout << "\n\n"
                        << "Are you done? "
                        << "\"Y\" for yes and \"N\" for No\n"
                        << std::endl;
              std::cin >> isFinished;

              if (isFinished == "Y" || isFinished == "y")
              {
                isFinishedLoop = false;
                keepRemoving = 0;
                removeNamesLoop = 0;
              }
              else if (isFinished == "N" || isFinished == "n")
              {
                isFinishedLoop = false;
                removeNamesLoop = true;
              }
              else
              {
                std::cout << "\n"
                          << "invalid" << "\n";
                isFinishedLoop = true;
                keepRemoving = false;
                i = 0;
              }
            }
          }

          // drawStarts=false;
        }
        selectionLoop = true;
      }

      else
      {
        std::cout << "\n\n\n"
                  << "Invalid! Try Again" << "\n\n"
                  << std::endl;
        selectionLoop = true;
      }
    }
  }
  return 0;
}
