#include <iostream>
#include <fstream>
#include "depend/include/nlohmann/json.hpp"

using namespace std;

int SearchId(nlohmann::json &x, int id)
{
    int k=-1;
    for (int i = 0; i < x.size(); i++)
    { 
        if (id == x[i]["id"]) {
            k = i; break;
        }
    }
    return k;
}

void update_json(string s, nlohmann::json& x1, nlohmann::json& x2)
{
    nlohmann::json::json_pointer p2(s);
    s+= '/';
    for (int i = 0; i < x1.at(p2).size(); i++)
    {
        nlohmann::json::json_pointer p1(s+to_string(i));

        if(SearchId(x2, x1.at(p1).at("id"))!=-1)
            x1.at(p1).at("value") = x2[SearchId(x2, x1.at(p1).at("id"))].at("value");

        if (x1.at(p1).find("values") != x1.at(p1).end())
            update_json(s+to_string(i)+"/values", x1, x2);
    }
}

int main(int argc, char* argv[])
{
    nlohmann::json objJson1, objJson2;
    ifstream in;

    in.open("tests.json");//argv[1]
    in >> objJson1;
    in.close();
    objJson1 = objJson1["tests"];

    in.open("values.json");//argv[2]
    in >> objJson2;
    in.close();
    objJson2 = objJson2["values"];

    update_json("",objJson1, objJson2);

    ofstream out;
    out.open("report.json");
    out << "{\"report\":[";
    for(int i=0; i< objJson1.size()-1;i++)
        out << objJson1[i]<<',';
    out << objJson1[objJson1.size()-1];
    out << "]}";
    out.close();

    return 0;
}


















/*for (int i = 0; i < objJson1.size(); i++)
    {
        string s = "";
        s='/' + to_string(i);
        objJson1[i]["id"]=objJson2[SearchId(objJson2, objJson1[i]["id"])]["id"];
        objJson1[i]["value"] = objJson2[SearchId(objJson2, objJson1[i]["id"])]["value"];
        //cout << objJson1[i] << endl<<endl;
        //
        nlohmann::json::json_pointer p1(s);
        nlohmann::json::json_pointer p2(s+"/values");        
        
        cout << objJson1[i] << endl << endl;

        if (objJson1.at(p1).find("values") != objJson1.at(p1).end())
        {
            for (int j = 0; j < objJson1.at(p2).size(); j++)
            {
                cout << objJson1.at(p2).at(j).at("id"); //= objJson2[SearchId(objJson2, objJson1.at(p2)["id"])]["id"];
                objJson1.at(p2).at(j).at("value")= objJson2[SearchId(objJson2, objJson1.at(p2).at(j).at("id"))].at("value");
                                                        //objJson1.at(p2)["value"] = objJson2[SearchId(objJson2, objJson1.at(p2)["id"])]["value"];
                /*while (objJson3.find("values") != objJson3.end())
                {
                    objJson3 = objJson3[i]["values"];
                    cout << objJson3 << endl;
                }
            }
        }
    }*/