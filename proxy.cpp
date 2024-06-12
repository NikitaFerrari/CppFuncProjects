#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;




class ServiceInterface {
public:
    virtual void operation() = 0;
};




class Service : public ServiceInterface{
    string path;
    
public:
    Service(string path) : path(path){}
    void operation() {
        cout << "Service Handling request " << endl;
    }
    vector <string> download() {
        vector <string> zapiska;
        ifstream in("text.txt");
        string str;
        if (in.is_open()) {
            while(getline(in, str)) {
                zapiska.push_back(str);
            }
        return zapiska;
        }

    }
    string downloadById(int id) {
       
        vector <string> zapiska;
            ifstream in("text.txt");
            string str;


            if (in.is_open()) {
                int index;
                while (getline(in, str)) {
                    string word = str.substr(0, str.find_first_of('.'));
                    if (id == stoi(word)){
                        return str;
                        
                    }
                }
            }

            
           

        }
    
    string getDate() {
        ifstream in("text.txt");
        string str;
        if (in.is_open()) {
            (getline(in, str));
                return str;
        }

    }



};



class Proxy : public ServiceInterface {
private:
    string data;
    Service* realService;
    bool checkAcces(int pass) {
        return (pass == 12345);
    }
public:
    Proxy(Service* realService) : realService(realService){}
    
    void operation() override {
        cout << "Proxy Handling request " << endl;
        int pass;
        cin >> pass;
        if (checkAcces(pass)) {
            realService->operation();
        }
    }

};









int main()
{
    Service* realService = new Service("text.txt");
    vector <string> vv=realService->download();
    for (auto el : vv) {
        cout << el << endl;
    }
    





}
