#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Item
{
    string name;
    int Damage_Max = 0;
    int Damage_Min = 0;
    int Armor_Max = 0;
    int Armor_Min = 0; 
};

struct Person
{ 
    string name;
    int Damage_Max = 0;
    int Damage_Min = 0;
    int Armor_Max = 0;
    int Armor_Min = 0;
};

void Read_Item(Item *item, char *argv)
{
    ifstream in_F(argv, ios::in);
    if (!in_F) cerr << "File " << *argv << "can not open";
    string line, attr;
    char attr_key;
    istringstream line_stream;
    int i = 0;
    while (getline(in_F, line))
    {
        //cout << "line: " << line << endl;
        line_stream.str(line);
        line_stream >> attr_key;
        //cout << " attr_key: " << attr_key << endl;
        if (attr_key == 'I')
        {
            line_stream >> attr;
            line_stream >> item[i].name; 
            //cout << item[i].name << endl;
        }

        else if (attr_key == 'A')
        {
            line_stream.ignore(5);
            line_stream >> item[i].Armor_Min >> item[i].Armor_Max;
            item[i].Armor_Max *= -1;
            if (item[i].Armor_Max == 0) item[i].Armor_Max = item[i].Armor_Min;
            //cout << item[i].Armor_Min << "-" << item[i].Armor_Max << endl;
        }

        else if (attr_key == 'D')
        {
            line_stream.ignore(6);
            line_stream >> item[i].Damage_Min >> item[i].Damage_Max;
            item[i].Damage_Max *= -1;
            if (item[i].Damage_Max == 0) item[i].Damage_Max = item[i].Damage_Min;
            //cout << item[i].Damage_Min << "-" << item[i].Damage_Max << endl;
        }

        else
        {
            i += 1;
            //cout << "i: " << i << endl;
        }
         
        line_stream.clear();
    }

    in_F.close();

}

void Read_Person(Person *person, char *argv, Item *item)
{
    ifstream in_F(argv, ios::in);
    string line, line_item;
    istringstream line_stream;
    int i = 0;

    while (getline(in_F, line))
    {
        line_stream.str(line);
        line_stream >> person[i].name;
        while (line_stream >> line_item)
        {
            //cout << line_item << endl;
            for (int j=0; j<13; j++)
            {
                //cout << "j: " << j << endl;
                if (line_item == item[j].name)
                {
                    //cout << "wow" << endl;
                    person[i].Damage_Min += item[j].Damage_Min;
                    person[i].Damage_Max += item[j].Damage_Max;
                    person[i].Armor_Min += item[j].Armor_Min;
                    person[i].Armor_Max += item[j].Armor_Max;
                    break; 
                }     
            } 
             
        }

        line_stream.clear();
        i += 1;
    } 
     
}

void Print_Person(Person *person)
{
    for (int i=0; i<3; i++)
    {
        cout.setf(ios::left);
        cout.width(8);
        cout << person[i].name;
        cout << "Damage:" << person[i].Damage_Min << "-"; 
        cout.width(6);
        cout << person[i].Damage_Max;
        cout << "Armor:" << person[i].Armor_Min << "-";
        cout.width(6);
        cout << person[i].Armor_Max;
        cout << endl;       
    }
}
int main(int argc, char **argv)
{
    Item item[13];
    Person person[3];
    Read_Item(item, argv[1]);
    /*for (int i=0; i<13; i++)
    {
        cout << item[i].name << endl;
        cout << item[i].Damage_Min << "-" << item[i].Damage_Max << endl; 
        cout << item[i].Armor_Min << "-" << item[i].Armor_Max << endl;
    }*/
    Read_Person(person, argv[2], item);
    Print_Person(person);
    /*for (int i=0; i<3; i++)
    {
        cout << person[i].name << endl;
        cout << person[i].Damage_Min << "-" << person[i].Damage_Max << endl; 
        cout << person[i].Armor_Min << "-" << person[i].Armor_Max << endl;
    }*/

}

