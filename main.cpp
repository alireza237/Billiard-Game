#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace sf;

double xc;
double yc;

vector<CircleShape> balls;
vector<double> v;
vector<double> h;
vector<double> vn;

int l = 0;

double hitx(double, sf::CircleShape, sf::CircleShape, double, double, double x, double y);
bool hole(double, double);

double hity(double, sf::CircleShape, sf::CircleShape, double, double, double x, double y);
double hitx1(double, sf::CircleShape, sf::CircleShape, double, double, double x, double y);
double hity1(double, sf::CircleShape, sf::CircleShape, double, double, double x, double y);

double ifhit();


int main() {
    double t, s, c, vx1 = 0, vy1 = 0, vx2 = 0, vy2 = 0, vx3 = 0, vy3 = 0, vx4 = 0,
            vy4 = 0, vx5 = 0, vy5 = 0, vx6 = 0, vy6 = 0, vx7 = 0, vy7 = 0, vx8 = 0,
            vy8 = 0, vx9 = 0, vy9 = 0, vx10 = 0, vy10 = 0;
    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");
    sf::RectangleShape shape(sf::Vector2f(800, 400));
    shape.setFillColor(sf::Color::Green);

    sf::RectangleShape r1(sf::Vector2f(165, 400));
    r1.setFillColor(sf::Color::Green);
    r1.setPosition(165, 0);

    sf::Vertex line[] =
            {
                    sf::Vertex(sf::Vector2f(165, 0)),
                    sf::Vertex(sf::Vector2f(165, 400))
            };

    sf::RectangleShape h1(sf::Vector2f(30, 3));
    h1.setFillColor(sf::Color::Black);
    h1.setPosition(385, 0);

    sf::RectangleShape h2(sf::Vector2f(30, 3));
    h2.setFillColor(sf::Color::Black);
    h2.setPosition(385, 397);

    sf::CircleShape cr(65);
    cr.setFillColor(sf::Color::Green);
    cr.setOutlineThickness(2);
    cr.setPosition(100, 135);
    cr.setOutlineColor(sf::Color::White);

    sf::CircleShape h3(20);
    h3.setFillColor(sf::Color::Black);
    h3.setPosition(-15, -15);

    sf::CircleShape h4(20);
    h4.setFillColor(sf::Color::Black);
    h4.setPosition(-15, 375);

    sf::CircleShape h5(20);
    h5.setFillColor(sf::Color::Black);
    h5.setPosition(775, -15);

    sf::CircleShape h6(20);
    h6.setFillColor(sf::Color::Black);
    h6.setPosition(775, 375);

    //ball
    //white
    sf::CircleShape bw(10);
    bw.setFillColor(sf::Color::White);
    bw.setPosition(90, 180);
    balls.push_back(bw);


    //yellow
    sf::CircleShape bb(10);
    bb.setFillColor(sf::Color::Yellow);
    bb.setPosition(155, 255);
    balls.push_back(bb);

    //blue
    sf::CircleShape blue(10);
    blue.setFillColor(sf::Color::Blue);
    blue.setPosition(390, 190);
    balls.push_back(blue);

    //brown
    sf::CircleShape brown(10);
    brown.setFillColor(sf::Color(150, 75, 0));
    brown.setPosition(155, 190);
    balls.push_back(brown);

    //Green
    sf::CircleShape green(10);
    green.setFillColor(sf::Color(0, 100, 0));
    green.setPosition(155, 125);
    balls.push_back(green);

    //purple
    sf::CircleShape purple(10);
    purple.setFillColor(sf::Color(128, 0, 128));
    purple.setPosition(588, 190);
    balls.push_back(purple);

    //black
    sf::CircleShape black(10);
    black.setFillColor(sf::Color::Black);
    black.setPosition(730, 190);
    balls.push_back(black);

    //red1
    sf::CircleShape red1(10);
    red1.setFillColor(sf::Color::Red);
    red1.setPosition(630, 201);
    balls.push_back(red1);

    //red2
    sf::CircleShape red2(10);
    red2.setFillColor(sf::Color::Red);
    red2.setPosition(630, 179);
    balls.push_back(red2);

    //red3
    sf::CircleShape red3(10);
    red3.setFillColor(sf::Color::Red);
    red3.setPosition(650, 168);
    balls.push_back(red3);

    //red4
    sf::CircleShape red4(10);
    red4.setFillColor(sf::Color::Red);
    red4.setPosition(650, 190);
    balls.push_back(red4);

    //red5
    sf::CircleShape red5(10);
    red5.setFillColor(sf::Color::Red);
    red5.setPosition(650, 213);
    balls.push_back(red5);

    //red6
    sf::CircleShape red6(10);
    red6.setFillColor(sf::Color::Red);
    red6.setPosition(670, 158);
    balls.push_back(red6);

    //red7
    sf::CircleShape red7(10);
    red7.setFillColor(sf::Color::Red);
    red7.setPosition(670, 179);
    balls.push_back(red7);

    //red8
    sf::CircleShape red8(10);
    red8.setFillColor(sf::Color::Red);
    red8.setPosition(670, 201);
    balls.push_back(red8);

    //red9
    sf::CircleShape red9(10);
    red9.setFillColor(sf::Color::Red);
    red9.setPosition(670, 223);
    balls.push_back(red9);

    //red10
    sf::CircleShape red10(10);
    red10.setFillColor(sf::Color::Red);
    red10.setPosition(610, 190);
    balls.push_back(red10);


    v = {0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    h = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vn = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (h[0]!=0){
            h[0]=0;
            bw.setPosition(90, 180);
            balls[0].setPosition(bw.getPosition());

        }

        if(v[0]<0.005) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                v[0] = ((bw.getPosition().x) - (sf::Mouse::getPosition(window).x)) / 100;

                vn[0] = ((bw.getPosition().y) - (sf::Mouse::getPosition(window).y)) / 100;

            }
        }
        int p =int(ifhit());

        if (p !=-1) {
            cout<<p<<" ";
            double a1=v[p/100],a2=vn[p/100],a3=v[p%100],a4=vn[p%100];
            vn[p/100] = hity(400, balls[p%100], balls[p/100], a1, a2, a3, a4);
            v[p/100] = hitx(400, balls[p%100], balls[p/100], a1, a2, a3, a4);

            vn[p%100] = hity1(400, balls[p%100], balls[p/100], a1, a2, a3, a4);
            v[p%100] = hitx1(400, balls[p%100], balls[p/100], a1, a2, a3, a4);


        }

        for (int i = 0; i < 22; ++i) {
            if (balls[i].getPosition().x < 0 or balls[i].getPosition().x > 780)
                v[i] = v[i] * (-1);
            if (balls[i].getPosition().y < 0 or balls[i].getPosition().y > 380)
                vn[i] = vn[i] * (-1);
        }

        for (int j = 0; j <22 ; ++j) {
            if (hole(balls[j].getPosition().x,balls[j].getPosition().y)){

                v[j]=0;
                vn[j]=0;
                h[j]=-1;
                balls[j].setPosition(-30,-30);

            }
        }

        for (int k = 0; k <22 ; ++k) {
            v[k]=v[k]-v[k]/700;
            vn[k]=vn[k]-vn[k]/700;
        }

        bw.move(sf::Vector2f(v[0], vn[0]));
        balls[0].setPosition(bw.getPosition());

        bb.move(sf::Vector2f(v[1], vn[1]));
        balls[1].setPosition(bb.getPosition());

        blue.move(sf::Vector2f(v[2], vn[2]));
        balls[2].setPosition(blue.getPosition());

        brown.move(sf::Vector2f(v[3], vn[3]));
        balls[3].setPosition(brown.getPosition());

        green.move(sf::Vector2f(v[4], vn[4]));
        balls[4].setPosition(green.getPosition());

        purple.move(sf::Vector2f(v[5], vn[5]));
        balls[5].setPosition(purple.getPosition());

        black.move(sf::Vector2f(v[6], vn[6]));
        balls[6].setPosition(black.getPosition());

        red1.move(sf::Vector2f(v[7], vn[7]));
        balls[7].setPosition(red1.getPosition());

        red2.move(sf::Vector2f(v[8], vn[8]));
        balls[8].setPosition(red2.getPosition());

        red3.move(sf::Vector2f(v[9], vn[9]));
        balls[9].setPosition(red3.getPosition());

        red4.move(sf::Vector2f(v[10], vn[10]));
        balls[10].setPosition(red4.getPosition());

        red5.move(sf::Vector2f(v[11], vn[11]));
        balls[11].setPosition(red5.getPosition());

        red6.move(sf::Vector2f(v[12], vn[12]));
        balls[12].setPosition(red6.getPosition());

        red7.move(sf::Vector2f(v[13], vn[13]));
        balls[13].setPosition(red7.getPosition());

        red8.move(sf::Vector2f(v[14], vn[14]));
        balls[14].setPosition(red8.getPosition());

        red9.move(sf::Vector2f(v[15], vn[15]));
        balls[15].setPosition(red9.getPosition());

        red10.move(sf::Vector2f(v[16], vn[16]));
        balls[16].setPosition(red10.getPosition());



        window.clear();
        window.draw(shape);
        window.draw(cr);
        window.draw(r1);
        window.draw(line, 3, sf::Lines);
        window.draw(h1);
        window.draw(h2);
        window.draw(h3);
        window.draw(h4);
        window.draw(h5);
        window.draw(h6);
        for (int n = 0; n <17 ; ++n) {
            if (h[n]==0)
                window.draw(balls[n])   ;
        }
        window.display();
    }
    return 0;
}

double hitx(double p, sf::CircleShape bb, sf::CircleShape bw, double vx1, double vy1, double x, double y) {
    vx1 = vx1 - ((vx1 - x) * ((bb.getPosition().x - 10) - (bw.getPosition().x - 10)) +
                 (vy1 - y) * ((bb.getPosition().y - 10) - (bw.getPosition().y - 10))) / p *
                ((bb.getPosition().x - 10) - (bw.getPosition().x - 10));
    return vx1;
}

double hity(double p, sf::CircleShape bb, sf::CircleShape bw, double vx1, double vy1, double x, double y) {
    vy1 = vy1 - ((vx1 - x) * ((bb.getPosition().x - 10) - (bw.getPosition().x - 10)) +
                 (vy1 - y) * ((bb.getPosition().y - 10) - (bw.getPosition().y - 10))) / p *
                ((bb.getPosition().y - 10) - (bw.getPosition().y - 10));
    return vy1;

}

double hity1(double p, sf::CircleShape bb, sf::CircleShape bw, double vx1, double vy1, double x, double y) {
    y = y - ((x - vx1) * ((bw.getPosition().x - 10) - (bb.getPosition().x - 10)) +
               (y - vy1) * ((bw.getPosition().y - 10) - (bb.getPosition().y - 10))) / p *
              ((bw.getPosition().y - 10) - (bb.getPosition().y - 10));

    return y;

}

double hitx1(double p, sf::CircleShape bb, sf::CircleShape bw, double vx1, double vy1, double x, double y) {
    x = x - ((x - vx1) * ((bw.getPosition().x - 10) - (bb.getPosition().x - 10)) +
               (y - vy1) * ((bw.getPosition().y - 10) - (bb.getPosition().y - 10))) / p *
              ((bw.getPosition().x - 10) - (bb.getPosition().x - 10));

    return x;

}

double ifhit() {
    double p;
    for (int i = 0; i < 17; ++i) {
        for (int j = 1; j <17 ; ++j) {
            double p = pow(((balls[i].getPosition().x - 10) - (balls[j].getPosition().x - 10)), 2) +
                       pow(((balls[i].getPosition().y - 10) - (balls[j].getPosition().y - 10)), 2);
            if (p <= 450 and p >= 350 and l == 0 and h[i]+h[j]==0) {
                return i + j * 100;
            }

        }
    }
    return -1;
}

bool hole(double x, double y){
    if ((x<20 and y<20 )or (x<20 and y>360 ) or (x>760 and y<20 ) or ( x>760 and y>360  )
        or (x<400 and x>385 and y<0) or( x<400 and x>385 and y>380) )
        return true;

    else return false;

}