#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
using std::string;
using namespace std;
class Package
{
private:
    string senderName;
    string senderCity;
    string recipientName;
    string recipientCity;
    double weight; // weight of the package
    double costPerWeight; // cost per weight to ship the package
public:
 /* any member functions if necessary */
    static size_t cnt;
    Package(string seName, string seCity, string reName, string reCity, double w, double cPW)
    {
        senderName = seName;
        senderCity = seCity;
        recipientName = reName;
        recipientCity = reCity;
        weight = w;
        costPerWeight = cPW; 
    }
    double calculateCost() {return weight*costPerWeight;}
    double Get_weight() {return weight;}
    void display_information()
    {
        cnt += 1;
        cout << "Package " << cnt << ':' << endl;
        cout << "Sender:" << endl;
        cout << senderName << " / " << senderCity << endl;
        cout << "Recipient: " << endl;
        cout << recipientName << " / " << recipientCity << endl;
        //cout << "Cost: $" << calculateCost() << endl;
    }
    void display_Cost() {cout << "Cost: $" << calculateCost() << endl;} //可以直接cout也OK 不用特別寫
    void display() {display_information(); display_Cost();}

};
size_t Package::cnt = 0;

class TwoDayPackage : public Package
{
private:
    double flatFee; // flat fee for two-day-delivery service
public:
    /* any member functions if necessary */
    TwoDayPackage(string seName, string seCity, string reName, string reCity, double w, double cPW, double flatF):
    Package(seName, seCity, reName, reCity, w, cPW), flatFee(flatF){ }
    double calculateCost() {return Package::calculateCost()+flatFee;}
    void display() {Package::display_information(); cout << "Cost: $" << calculateCost() << endl;}
};

class OvernightPackage : public Package
{
private:
    double overnightFreePerWeight; // flat fee weight for overnight delivery
public:
    /* any member functions if necessary */
    OvernightPackage(string seName, string seCity, string reName, string reCity, double w, double cPW, double overFPW):    Package(seName, seCity, reName, reCity, w, cPW), overnightFreePerWeight(overFPW){ }
    double calculateCost() {return Package::calculateCost()+Package::Get_weight()*overnightFreePerWeight;}
    void display() {Package::display_information(); cout << "Cost: $" << calculateCost() << endl;}
};
#endif 
