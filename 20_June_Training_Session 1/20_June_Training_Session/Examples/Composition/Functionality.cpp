#include "Functionality.h"

void CreateObjects(Container &accounts)
{
    accounts.emplace_back(
        new BankAccount
        {9384,
        "abc",
        8394.0,
        BankAccountType::CURRENT,
        new DebitCard(
            DebitCardType::VISA,
            889,
            "08/2029",
            938475849
            )
        } 
        );
    accounts.emplace_back(new BankAccount{8273,"ker",1310.0,BankAccountType::PENSION,new DebitCard{DebitCardType::AMEX,190,"12/2030",298438849}});
    accounts.emplace_back(new BankAccount{5254,"jeg",2830.0,BankAccountType::SAVINGS,new DebitCard{DebitCardType::DINERSCLUB,783,"10/2031",84138349}});
    accounts.emplace_back(new BankAccount{1638,"eeu",6624.0,BankAccountType::CURRENT,new DebitCard{DebitCardType::MASTERCARD,263,"09/2035",273748509}});

}

void DisplayDebitCardDetails(const Container &accounts, long number)
{
    bool flag=false;
    for (const BankAccount* b: accounts)
    {
        if (b && b->accountNumber()==number)
        {
            std::cout<<*(b->attachedCard())<<"\n";
            flag=true;
            break;
        }
    }

    if (!flag)
    {
        throw NumberNotFound("Number not found");
    }
    
}

void CountVISACards(Container &accounts)
{
    int count=0;
    bool flag=false;
       for (const BankAccount* b: accounts)
    {
        if (b && b->attachedCard()->cardType()==DebitCardType::VISA)
        {
            flag=true;
            count++;
        }
    }

    if (!flag)
    {
        throw NoValidPointer("No valid pointer");
    }
    

    std::cout<<"Number of visa::"<<count<<"\n";


}

void Deallocation(Container &accounts)
{
    for(BankAccount* b:accounts){
        delete b;
    }
}
