/********************************************************************************
  *                                                                              *
  * CS 372                                                                       *
  * points Class Graphing                                                        *
  *                                                                              *
  * Description: This program uses points on x/y coordinates and manipulates them*
  ********************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <math.h>

using namespace std;

class point
{
private:
    float x;   //x coordinate 
    float y;   //y coordinate 
    
public:
    //default constructor
    point()
    {
        x=0.0;
	y=0.0;
    }
	
	point(float v1, float v2)
	{
		x=v1;
		y=v2;	
	}

    
    void shift(float x_amount, float y_amount);
    int rotations_needed(point);
    void rotate90();
    float get_x() const;  
    float get_y() const;
    void translation(float x_amount, float y_amount);
    void scaling(float x_amount, float y_amount);
    void rotation(int degree);
    void shearing(float factor, char direction);

};

point middle(const point& p1, const point& p2);
float distance(const point& p1, const point& p2);

 point middle(const point& p1, const point& p2)  //returns the midpoint between two points

{
   float x_midpoint, y_midpoint;

   // Compute the x and y midpoints
   x_midpoint = (p1.get_x() + p2.get_x()) / 2;
   y_midpoint = (p1.get_y() + p2.get_y()) / 2;

   point midpoint(x_midpoint, y_midpoint);

    return midpoint;

}
 
 float distance(const point& p1, const point& p2)  //finding the distance between two points 
{
   float a, b, c_squared;

   a = p1.get_x() - p2.get_x(); // Difference in x coordinates
   b = p1.get_y() - p2.get_y(); // Difference in y coordinates

  // Pythagorean Theorem to calculate square of distance between points
   c_squared = a*a + b*b;

   return sqrt(c_squared); // sqrt calculates square root (from math.h)
}

void point:: shift(float x_amount, float y_amount)  //method to shift the points 
{
    x+= x_amount;
    y+= y_amount;

    //printing out the result 
    cout<<" by ("<<x_amount<<","<<y_amount<<")"<<endl;
    cout<<"is: ("<<x<<","<<y<<")"<<endl;
}


int point::rotations_needed(point p)  //find out how many rotations you need to move the point to the upper right 
{
    int total=0;
    
    while((p.get_x() < 0) || (p.get_y() < 0))
    {
        p.rotate90();
        ++total;
    }

    return total;
}

void point:: rotate90()  //rotate the points 90 degrees 
{
    float new_x;
    float new_y;
    
    new_x = y; //90 degrees clockwise rotation, new x is original y 
    new_y = -x; //new y is -1 times the original x 
    
    x = new_x;
    y = new_y;
    
    cout<<"("<<x<<","<<y<<")";
}

float point:: get_x() const  //getting the value of x 
{
    return x;
}

float point:: get_y() const //getting the value of y
{
    return y;
}

void point:: translation(float x_amount, float y_amount)  //the translation formula 
{
    float new_x, new_y;
    
    new_x=x+x_amount;
    new_y=y+y_amount;
    
    cout<<"("<<new_x<<","<<new_y<<")";
}

void point:: scaling(float x_amount, float y_amount)  //the scaling formula 
{
    float new_x, new_y;
    
    new_x=x*x_amount;
    new_y=y*y_amount;
    
     cout<<"("<<new_x<<","<<new_y<<")"; 
}
 
void point:: rotation(int degree)   //the rotation formula 
{
    float new_x;
    float new_y;
    
    float radians;
    radians=degree*3.14159/180;
    
    new_x = cos(radians)*x + sin(radians)*y;
    new_y = sin(radians)*x + cos(radians)*-y;
    
    cout<<"("<<new_x<<","<<new_y<<")"; 
}

void point:: shearing(float factor, char direction)  //the shearing formula 
{
    float newCor;
    
    if(direction=='x')
    {
        newCor=x+factor;
        cout<<"("<<newCor<<","<<y<<")";
    }
    
    if(direction=='y')
    {
        newCor=y+factor;
        cout<<"("<<x<<","<<newCor<<")";
    }
}

void header()  //header
{
    
    cout<<"***************************************"<<endl;
    cout<<"Output for Points Graphing Program"<<endl;
    cout<<"***************************************"<<endl<<endl;	
}


int main()
{
    char direct_x='x';  //direction of x
    char direct_y='y';  //direction of y 
    
    int total;
    
    //objects for first half
    point sample1(-2,5);
    point sample2(3,3);
    point sample3(-5,4);
    point sample4(2,5);
    point sample5(8,3);
    point sample6(5,4);
    point sample8(6,3);
    point sample9(4,8);
    
    //objects for box half
    point p1(2,2);
    point p2(2,5);
    point p3(4,5);
    point p4(4,2);
    
    cout<<fixed<<setprecision(0);
    
    header();
    
    //testing the shift function
    cout<<"Testing the shift function"<<endl;
    cout<<"Shifting the sample ("<<sample1.get_x()<<","<<sample1.get_y()<<")";
    sample1.shift(2,2);
    
    //another shift test
    cout<<"Shifting the sample ("<<sample2.get_x()<<","<<sample2.get_y()<<")";
    sample2.shift(-5,4);
    cout<<endl;
    
    //testing the rotate90 function
    cout<<"Testing the rotate90 function"<<endl;
    cout<<"The point: ("<<sample9.get_x()<<","<<sample9.get_y()<<") rotated 90 degrees is: ";
    sample9.rotate90();
    cout<<endl<<endl;
    
    //finding out how many rotations are needed to move the point to the upper right quadrant
    cout<<"Testing how many rotations are needed to move a point to the upper right quadrant"<<endl;
    
    //sample 3
    cout<<"The number of 90 degree rotations needed to move the point ("<<sample3.get_x()<<","<<sample3.get_y();
    cout<<") to the upper right at ";
    sample3.rotations_needed(sample3);
    cout<<" is: "<<total<<endl<<endl;
   
    
    //testing the distance method 
    cout<<"Testing the distance method"<<endl;
    cout<<"The distance between Point ("<<sample6.get_x()<<","<<sample6.get_y()<<")";
    cout<<"and ("<<sample8.get_x()<<","<<sample8.get_y()<<") is: ";
    cout<<setprecision(1)<<distance(sample6, sample8);
     cout<<setprecision(0)<<endl<<endl;
    
    //testing the middle method to find the midpoint between two points
     cout<<"Testing the midpoint function"<<endl;
     point midpoint=middle(sample4,sample5);
     cout<<"The midpoint between point ("<<sample4.get_x()<<","<<sample4.get_y()<<")";
     cout<<" and point ("<<sample5.get_x()<<","<<sample5.get_y()<<") is ("<<midpoint.get_x()<<","<<midpoint.get_y()<<")"<<endl<<endl;
     
    
    //the box before any calculations done
    cout<<"The box before any calculations have been done"<<endl;
    cout<<"("<<p2.get_x()<<","<<p2.get_y()<<")"; 
    cout<<"---------";
    cout<<"("<<p3.get_x()<<","<<p3.get_y()<<")"; 
    
    cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<setw(5)<<"|"<<setw(10)<<"|"<<endl;
    }
   
    cout<<"("<<p1.get_x()<<","<<p1.get_y()<<")"; 
    cout<<"---------";
    cout<<"("<<p4.get_x()<<","<<p4.get_y()<<")";
    
    cout<<endl<<endl;
   
  
    
    //box after translation of x=2 and y=1 distance
    cout<<"The box after translating x=2 and y=1"<<endl;
      p2.translation(2,1);
       cout<<"---------";
      p3.translation(2,1);
      cout<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<setw(5)<<"|"<<setw(10)<<"|"<<endl;
    }
      
     p1.translation(2,1);
       cout<<"---------";
     p4.translation(2,1);
     cout<<endl<<endl;
     
     //box after scaling x by 2 and y by 0.5
     cout<<"The box after scaling x by 2 and y by 0.5"<<endl;
      p2.scaling(2, 0.5);
      cout<<"-------------------";
      p3.scaling(2, 0.5);
       for(int i=0;i<4;i++)
    {
        cout<<setw(5)<<"|"<<setw(20)<<"|"<<endl;
    }
      
       p1.scaling(2, 0.5);
        cout<<"-------------------";
      p4.scaling(2, 0.5);
      cout<<endl<<endl;
      
      
      cout<<fixed<<setprecision(1);
     //the original box after rotating it 30 degrees
      cout<<"The original box after rotating 30 degrees"<<endl;
     cout<<"         ";
          p4.rotation(30);
          for(int i=0;i<5;i++)
          {
              cout<<endl;
          }
          
         p1.rotation(30); 
         for(int i=0;i<4;i++)
          {
              cout<<endl;
          }
       
         cout<<"                            ";
         p3.rotation(30);
          for(int i=0;i<4;i++)
          {
              cout<<endl;
          }
         cout<<"            ";
      p2.rotation(30);
      cout<<endl<<endl;
      
      //The new box rotated another 60 degrees
      cout<<"The box after rotating another 60 degrees"<<endl;
      
      cout<<"y"<<endl;
      for(int i=0;i<5;i++)
      {
          cout<<"|"<<endl;
      }
      cout<<"_____________________________________X"<<endl;
      
      
     
      p1.rotate90();
      cout<<"----------------";
      p2.rotate90();
       for(int i=0;i<7;i++)
       {
        cout<<setw(6)<<"|"<<setw(26)<<"|"<<endl;
       }
      p4.rotate90();
      cout<<"----------------";
       p3.rotate90();
      cout<<endl<<endl;
      
      
      //printing the original box after shearing x=1.5
      cout<<"The original box after shearing x=1.5"<<endl<<endl;
      p2.shearing(1.5,direct_x);
      cout<<"---------";
      p3.shearing(1.5,direct_x);
      for(int i=0;i<7;i++)
       {
        cout<<setw(7)<<"|"<<setw(15)<<"|"<<endl;
       }
      p1.shearing(1.5,direct_x);
      cout<<"---------";
      p4.shearing(1.5,direct_x);
      
      cout<<endl<<endl;
      
      //printing the original box after shearing y=1.7
      cout<<"The original box after shearing y=1.7"<<endl;
      p2.shearing(1.7, direct_y);
      cout<<"---------";
      p3.shearing(1.7, direct_y);
    
      for(int i=0;i<7;i++)
       {

               cout<<setw(7)<<"|"<<setw(15)<<"|"<<endl;
       
       }
       p1.shearing(1.7, direct_y);
       cout<<"---------";
      p4.shearing(1.7, direct_y);
    

    
    return 0;
}
