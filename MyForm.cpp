/*author: Lauren Abrishami
date: 4/30/20
purpose: A GUI will be displayed. The user may choose to sort integers or-
fractions in ascending or descending order. Commas or whitespace is allowed-
between numbers/fractions, but not both at once.*/


#include "MyForm.h"
#include <iostream>
#include "ProcessInput.h"
#include <string>
#include <regex>
#include <sstream>
#include <iostream>
#include <exception>

using namespace std;
using namespace Project1;
using namespace System::Windows::Forms;



void MyForm::sort_button_Click(System::Object^ sender, System::EventArgs^ e) {
    msclr::interop::marshal_context context;
    try {
        //converting system string to std string
        
        String^ sorted_string;
        UserInput = context.marshal_as<std::string>(input_list->Text);
        ProcessInput pi(UserInput);
        if (ascending_button->Checked && int_button->Checked == true
            && !fracButton->Checked && !descending_button->Checked) {


            sorted_string = gcnew String(pi.TokenizeInt("ascending").c_str());




        }
        else if (descending_button->Checked == true && int_button->Checked == true
            && !fracButton->Checked && !ascending_button->Checked) {

            sorted_string = gcnew String(pi.TokenizeInt("descending").c_str());


        }
        else if (descending_button->Checked == true && fracButton->Checked == true
            && !int_button->Checked && !ascending_button->Checked) {

            sorted_string = gcnew String(pi.TokenizeFraction("descending").c_str());


        }
        else if (ascending_button->Checked == true && fracButton->Checked == true
            && !int_button->Checked && !descending_button->Checked) {

            //converting output string to system string
            sorted_string = gcnew String(pi.TokenizeFraction("ascending").c_str());
        }
        else {
            printf("Please only select ascending or descending");
            printf("and fraction or integer.");
        }
        
        sorted_list->Clear();
        sorted_list->AppendText(sorted_string);
        sorted_list->Refresh();
        
    }
    catch(System::Exception^ ex) {
        printf("bad input.");
    }
    }
   





int main()
{

    //This works!
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project1::MyForm form;
    Application::Run(% form);
    
    return 0;
};



