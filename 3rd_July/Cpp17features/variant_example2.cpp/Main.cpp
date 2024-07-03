#include "Employee.h"
#include "BusinessOwner.h"
#include <variant>

using vrType = std:: variant<BusinessOwner, Employee>;
void Display(VrType& vr)    {

    std::visit( [] (val) {std::cout<<val << "\n";} , v);
}




int main(){

 vrType vr;
 std:: variant<BusinessOwner, Employee> vr;
 Employee e1 {"Anju", 96945.0f};
 BusinessOwner b1 {"Anju", 84658.0f};
 vr = e1;

 Display(vr);

 vr = b1; // changed vs to businessowner

 Display(vr);
}