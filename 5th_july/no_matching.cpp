
#include <iostream>
#include <string>

//  Part 2
// int createN1(){
//     int n1{10};
// }
// int main(){
//     int n1 = createN1();
//     std::cout << n1;
// }
 
void Display(char grade)
{
 
    std::cout << grade << "\n";
}
 
void Demo(int n1, std::string name)
{
 
    std::cout << n1 << name << "\n";
}
 
void Temp(float n1, int *ptr, std::string name, char &&grade, const bool &flag)
{
 
    std::cout << "\t" << n1 << "\t" << *ptr << "\t" << name << "\t" << grade << "\t" << flag << "\n";
}
 
int main()
{
    Display('A');
 
    Demo(10, "abc");
 
    Temp(34.5f, NULL, "Anju", 'A', false);
}
 
 

/*Demo -it is a function 
1st parameter is non const int value
2nd parameter is non const string value 
which returns void

-lpthread - undefiend reFERENCE TO thread

*/