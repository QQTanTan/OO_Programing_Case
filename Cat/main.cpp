#include <iostream>
#include <stdio.h>

using namespace std;

void CatTest();
void CatOneMonth();

class Cat{
public:

    Cat(const string &name);
    void talk();
    void eat(int);
    void drink(int);
    void sleep(int);
    void sport(int);
private:
    string name;
    int food;
    int water;
    int time;
    int weight;
    int age;
};

Cat::Cat(const string& name) : name(name),food(0),water(0),weight(80),age(0) {}

void Cat::talk(){
    cout<<name<<"(age = "<<age<<" weight = "<<weight<<" food = "<<food<<" water = "<<water<<" ) "<<endl;
}

void Cat::eat(int f){
    food += f;
}

void Cat::drink(int w){
    water += w;
}

void Cat::sleep(int s){
    if(food >= s) food -= s;
    else {

        weight -= (s - food);
        food = 0;
    }
    if(water >= s) water -= s;
    else {

        weight -= (s - water);
        water = 0;
    }
    weight += s;
    age += s;
}

void Cat::sport(int h){
    food -= 3 * h;
    water -= 3 * h;
    weight += h;
    age += h;
    if(food < 0){
        weight += food;
        food = 0;
    }
    if(water < 0){
        weight += water;
        water = 0;
    }
}

void CatTest(){
    Cat cat("Miaomi");
    cat.talk();
    cat.eat(10);
    cat.talk();
    cat.drink(5);
    cat.talk();
    cat.sleep(4);
    cat.talk();
    cat.sport(1);
    cat.talk();
}

void CatOneMonth(){
    Cat cat("xiaohua");
    int day;
    for(day = 0; day < 30; day++){
        cat.sport(1);

        cat.eat(4);
        cat.drink(6);
        cat.sleep(4);

        cat.eat(6);
        cat.drink(4);
        cat.sport(2);

        cat.sleep(4);

        cat.sport(1);

        cat.eat(10);
        cat.drink(10);
        cat.sport(1);

        cat.sleep(6);
        cat.sport(1);

        cat.eat(6);
        cat.drink(6);

        cat.sleep(4);
    }
    cat.talk();
}

int main()
{
    CatTest();
    CatOneMonth();
}
