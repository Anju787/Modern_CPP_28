/*
    Employee
        - int id, string name, string designation, categorical Department, float salary
    
    use default to enable and delete to disable
*/

#include<iostream>
#include "Department.h"

class Employee
{
private:
    unsigned int m_id {0};//Default value of m_id is 0
    std::string m_name {""};//Default value of m_name is ""
    std::string m_designation {"executive"};
    enum Department m_dept {Department::IT};
    float m_salary {0.0f};
public:
    Employee() = default;//enable the default constructor 
    ~Employee() = default; //destructor is enabled
    Employee(const Employee& other) = delete; //disable copy  
    Employee& operator = (const Employee& other) = default;
    Employee(Employee&& other) = delete; //move constructor
    Employee& operator = (Employee&& other) = delete;
    Employee(unsigned int id,std::string name, std::string des, Department dept, float salary): m_id {id}, m_dept{dept}, m_designation{des}, m_name {name}, m_salary {salary} {}
};


int main(){
    Employee *e1=new Employee();
    Employee *ptr=nullptr;// declaration of a pointer ptr of type Employee
    ptr=new Employee();
    ptr = new Employee(101,"abc","student",Department::IT, 9000.0f);
    int n1 {10};
    Employee e0;
    Employee e2;
    e0=e2;
    int* ptr {nullptr};
    
    int arr[3] {1,2,3};

    Employee e1 {102,"bcd","ieng",Department::ACCOUNTS,94859.6};

}