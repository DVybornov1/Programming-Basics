#include <iostream>
#include <math.h> 
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <list>
using namespace std;
using std::string;

int II(int x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

bool IB(bool x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

string IS(string x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

char IC(char x) {
    cin >> x;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n" << "Invalid input." << "\n" << "\n";
        cin >> x;
    }
    return x;
}

class animal {
    public:
        string name;
        string breed;
        int age;
        int weight;

        void eat() {
            cout << "\n" << name << " eats." << "\n\n";
        }
        void move() {
            cout << "\n" << name << " runs around." << "\n\n";
        }
        void sleep() {
            cout << "\n" << name << " sleeps." << "\n\n";
        }
};

class shark: public animal {
    public:
        bool canliveinfreshwater;
        bool agressivetohumans;
        void move() {  //Unique inh.
            cout << "\n" << name << " swims around." << "\n\n";
        }
        void prowl() {
            cout << "\n" << name << " slowly swims near the walls of its aviary ." << "\n\n";
        }
        void circle() {
            cout << "\n" << name << " swims in a circle." << "\n\n";
        }
        void gesture() {
            cout << "\n" << "You gesture at " << name << ".\n" << name << " is not impressed.\n\n";
        }
        void pet() {
            cout << "\n" << "You pet " << name << ".\n" << name << " seems to appreciate that.\n\n";
        }
        shark(string q, string w, int e, int r, bool t, bool y) {
            name = q;
            breed = w;
            age = e;
            weight = r;
            canliveinfreshwater = t;
            agressivetohumans = y;
        }
};

class canine: public animal {
    public:
        bool trainable;
        string furcolor;
        void howl() {
            cout << "\n" << name << " howls." << "\n\n";
        }
        void move() {  //Unique inh.
            cout << "\n" << name << " slowly patrols its aviary." << "\n\n";
        }
        void rest() {
            cout << "\n" << name << " lies under a tree." << "\n\n";
        }
        void gesture() {
            cout << "\n" << "You gesture at " << name << ".\n" << name << " ignores you.\n\n";
        }
        void pet() {
            cout << "\n" << "You pet " << name << ".\n" << name << " is happy.\n\n";
        }
        canine(string q, string w, int e, int r, bool t, string y) {
            name = q;
            breed = w;
            age = e;
            weight = r;
            trainable = t;
            furcolor = y;
        }
};

class marsupial: public animal {
    public:
        bool issociable;
        bool candigesthumanfood;
        void move() {  //Unique inh.
            cout << "\n" << name << " runs and jumps around." << "\n\n";
        }
        void stare() {
            cout << "\n" << name << " looks at the visitors." << "\n\n";
        }
        void rest() {
            cout << "\n" << name << " calmly sits on a tree branch." << "\n\n";
        }
        void gesture() {
            cout << "\n" << "You gesture at " << name << ".\n" << name << " stares at you.\n\n";
        }
        void pet() {
            cout << "\n" << "You pet " << name << ".\n" << name << " seems to like you.\n\n";
        }
        marsupial(string q, string w, int e, int r, bool t, bool y) {
            name = q;
            breed = w;
            age = e;
            weight = r;
            issociable = t;
            candigesthumanfood = y;
        }
};

int main() {

string sprompt1 = "";
string sprompt2 = "";
char cprompt = 'x';
bool bprompt = false;
int iprompt = 0;
string q;
string w;
string e;
int r;
int t;
bool y;
bool u;

srand(4);

list<shark> sharklist = {};
list<canine> caninelist = {};
list<marsupial> marsupiallist = {};

cout << "\n" << "Add the default set of 3 animals? (y/n)\n\n";
cprompt = IC(cprompt);
if (cprompt == 'y') {
    shark shark1("Bridget", "Tiger Shark", 20, 500, false, false);
    sharklist.push_back(shark1);
    canine canine1("Rusty", "Grey Wolf", 8, 35, true, "blue-ishe gray");
    caninelist.push_back(canine1);
    marsupial marsupial1("Riggs", "Virginia Opossum", 1, 2, true, true);
    marsupiallist.push_back(marsupial1);
    cout << "\n" << "Animals added.\n" << "Add 3 more animals? (y/n)\n\n";
    cprompt = IC(cprompt);
    if (cprompt == 'y') {
        shark shark1("Vergil", "Orca", 64, 6422, true, true);
        sharklist.push_back(shark1);
        canine canine1("Ena", "Shiba Inu", 6, 7, false, "Yellow");
        caninelist.push_back(canine1);
        marsupial marsupial1("Khorne", "Red Kangaroo", 16, 38, false, false);
        marsupiallist.push_back(marsupial1);
        cout << "\n" << "Animals added.\n\n";
    } else if (cprompt == 'n') {
        cout << "\n" << "Ok.\n\n";
    } else {
        cout << "\n" << "Invalid input.\n\n";
    }
} else if (cprompt == 'n') {
    cout << "\n" << "Ok.\n\n";
} else {
    cout << "\n" << "Invalid input.\n\n";
}

cout << "Type 'QUIT' to quit, type 'help' for help.\n\n";
while (sprompt1 != "QUIT") {
    cout << "Enter command.\n\n";
    sprompt1 = IS(sprompt1);
    cin.ignore();
    if (sprompt1 == "inspect") {
        cout << "\n" << "Enter name.\n\n";
        getline(cin, sprompt1);
        cout << "\n" << "Enter species.\n\n";
        sprompt2 = IS(sprompt2);
        if (sprompt2 == "shark") {
            for(shark x : sharklist) {
                if (x.name == sprompt1) {
                    cout << "\n" << x.name << " (" << x.breed << ")\n" << "- Is " << x.age << " year(s) old.\n" << "- Weights " << x.weight << " kg.\n";
                    if (x.canliveinfreshwater == true) {
                        cout << "- "<< x.name << " can live in freshwater.\n";
                    } else {
                        cout << "- "<< x.name << " can't live in freshwater.\n";
                    }
                    if (x.agressivetohumans == true) {
                        cout << "- "<< x.name << " is agressive to humans.\n\n";
                    } else {
                        cout << "- "<< x.name << " isn't agressive to humans.\n\n";
                    }
                }
            } 
        } else if (sprompt2 == "canine") {
            for(canine x : caninelist) {
                if (x.name == sprompt1) {
                    cout << "\n" << x.name << " (" << x.breed << ")\n" << "- Is " << x.age << " year(s) old.\n" << "- Weights " << x.weight << " kg.\n";
                    if (x.trainable == true) {
                        cout << "- "<< x.name << " can be trained.\n";
                    } else {
                        cout << "- "<< x.name << " can't be trained.\n";
                    }
                        cout << "- " << x.name << "'s fur color is " << x.furcolor << ".\n\n";
                }
            }
        } else if (sprompt2 == "marsupial") {
            for(marsupial x : marsupiallist) {
                if (x.name == sprompt1) {
                    cout << "\n" << x.name << " (" << x.breed << ")\n" << "- Is " << x.age << " year(s) old.\n" << "- Weights " << x.weight << " kg.\n";
                    if (x.issociable == true) {
                        cout << "- " << x.name << " is sociable.\n";
                    } else {
                        cout << "- " << x.name << " isn't sociable.\n";
                    }
                    if (x.candigesthumanfood == true) {
                        cout << "- " << x.name << " can digest human food.\n\n";
                    } else {
                        cout << "- " << x.name << " can't digest human food.\n\n";
                    }
                }
            }
        } else if (sprompt2 == "QUIT") {
            cout << "\n";
            break;
        } else {
            cout << sprompt2 << " is not a valid class. Try again.\n\n";
        }
    } else if (sprompt1 == "idle") {
        cout << "\n" << "Enter name.\n\n";
        getline(cin, sprompt1);
        cout << "\n" << "Enter species.\n\n";
        sprompt2 = IS(sprompt2);
        iprompt = (rand() % 5);
        if (sprompt2 == "shark") {
            for(shark x : sharklist) {
                if (x.name == sprompt1) {
                    if (iprompt == 0) {
                        x.move();
                    } else if (iprompt == 1) {
                        x.eat();
                    } else if (iprompt == 2) {
                        x.sleep();
                    } else if (iprompt == 3) {
                        x.prowl();
                    } else if (iprompt == 4) {
                        x.circle();
                    }
                }
            } 
        } else if (sprompt2 == "canine") {
            for(canine x : caninelist) {
                if (x.name == sprompt1) {
                    if (iprompt == 0) {
                        x.move();
                    } else if (iprompt == 1) {
                        x.eat();
                    } else if (iprompt == 2) {
                        x.sleep();
                    } else if (iprompt == 3) {
                        x.howl();
                    } else if (iprompt == 4) {
                        x.rest();
                    }
                }
            }
        } else if (sprompt2 == "marsupial") {
            for(marsupial x : marsupiallist) {
                if (x.name == sprompt1) {
                    if (iprompt == 0) {
                        x.move();
                    } else if (iprompt == 1) {
                        x.eat();
                    } else if (iprompt == 2) {
                        x.sleep();
                    } else if (iprompt == 3) {
                        x.stare();
                    } else if (iprompt == 4) {
                        x.rest();
                    }
                }
            }
        } else if (sprompt2 == "QUIT") {
            break;
        } else {
            cout << "Invalid class. Try again.\n\n";
        }
    } else if (sprompt1 == "gesture") {
        cout << "\n" << "Enter name.\n\n";
        getline(cin, sprompt1);
        cout << "\n" << "Enter species.\n\n";
        sprompt2 = IS(sprompt2);
        if (sprompt2 == "shark") {
            for(shark x : sharklist) {
                if (x.name == sprompt1) {
                    x.gesture();
                }
            } 
        } else if (sprompt2 == "canine") {
            for(canine x : caninelist) {
                if (x.name == sprompt1) {
                    x.gesture();
                }
            }
        } else if (sprompt2 == "marsupial") {
            for(marsupial x : marsupiallist) {
                if (x.name == sprompt1) {
                    x.gesture();
                }
            }
        } else if (sprompt2 == "QUIT") {
            break;
        } else {
            cout << "Invalid class. Try again.\n\n";
        }
    } else if (sprompt1 == "pet") {
        cout << "\n" << "Enter name.\n\n";
        getline(cin, sprompt1);
        cout << "\n" << "Enter species.\n\n";
        sprompt2 = IS(sprompt2);
        if (sprompt2 == "shark") {
            for(shark x : sharklist) {
                if (x.name == sprompt1) {
                    x.pet();
                }
            } 
        } else if (sprompt2 == "canine") {
            for(canine x : caninelist) {
                if (x.name == sprompt1) {
                    x.pet();
                }
            }
        } else if (sprompt2 == "marsupial") {
            for(marsupial x : marsupiallist) {
                if (x.name == sprompt1) {
                    x.pet();
                }
            }
        } else if (sprompt2 == "QUIT") {
            break;
        } else {
            cout << "Invalid class. Try again.\n\n";
        }
    } else if (sprompt1 == "list") {
        cout << "\n" << "Sharks: ";
        for (shark x : sharklist) {
            cout << x.name << " (" << x.breed << "), ";
        }
        cout << "\n" << "Canines: ";
        for (canine x : caninelist) {
            cout << x.name << " (" << x.breed << "), ";
        }
        cout << "\n" << "Marsupials: ";
        for (marsupial x : marsupiallist) {
            cout << x.name << " (" << x.breed << "), ";
        }
        cout << "\n\n";
    } else if (sprompt1 == "QUIT") {
        break;
    } else if (sprompt1 == "add") {
        cout << "\n" << "Enter species. ('shark', 'canine' or 'marsupial')" << "\n\n";
        sprompt1 = IS(sprompt1);
        cout << "\n" << "Enter name." << "\n\n";
        cin.ignore();
        getline(cin, q);
        cout << "\n" << "Enter breed." << "\n\n";
        getline(cin, w);
        cout << "\n" << "Enter age." << "\n\n";
        r = II(r);
        cout << "\n" << "Enter weight." << "\n\n";
        t = II(t);
        if (sprompt1 == "shark") {
            cout << "\n" << "Can " << q << " live in freshwater?\n\n";
            y = IB(y);
            cout << "\n" << "Is " << q << " agressive to humans?\n\n";
            u = IB(u);
            shark nshark(q, w, r, t, y, u);
            sharklist.push_back(nshark); 
        }if (sprompt1 == "canine") {
            cout << "\n" << "Can " << q << " be trained?\n\n";
            y = IB(y);
            cout << "\n" << "What is the color of " << q << "'s fur?\n\n";
            e = IS(e);
            canine ncanine(q, w, r, t, y, e);
            caninelist.push_back(ncanine);
        } else if (sprompt1 == "marsupial") {
            cout << "\n" << "Is " << q << " sociable?\n\n";
            y = IB(y);
            cout << "\n" << "Is " << q << " able to digest human food?\n\n";
            u = IB(u);
            marsupial nmarsupial(q, w, r, t, y, u);
            marsupiallist.push_back(nmarsupial);
        } else {
            cout << "Invalid species.\n\n";
            break;
        }
        cout << "\n" << "New animal added.\n\n";
    } else if (sprompt1 == "help") {
        cout << "\n" << "The available commands are:\nlist\ninspect\nidle\ngesture\npet\nadd\nQUIT\n\n"; 
    } else {
        cout << "Invalid.\n\n";
    }
}  // ?????????
}