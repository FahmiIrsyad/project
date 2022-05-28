#include <iostream>
#include <fstream>
using namespace std;
class cylinder{
	public:
		double height,radius;
		
};
int main(){
   cylinder clinder[3];
   ofstream outputfile;
   outputfile.open("cylinders.txt");
   double volume[3],area[3];

   for(int i=0;i<3;i++){
   	cout<<"Enter the radius for Cylinder "<<i+1<<":";
   	cin>>clinder[i].radius;
   	cout<<"Enter the height for Cylinder "<<i+1<<":";
   	cin>>clinder[i].height;
   	}
   	cout<<"\n";
   	for(int i=0;i<3;i++){
   			volume[i]=(3.142*clinder[i].radius*clinder[i].radius*clinder[i].height);
   			area[i]=(2*3.142*clinder[i].radius*clinder[i].height)+(2*3.142*clinder[i].radius*clinder[i].radius);	
   	        outputfile<<"Volume for Cylinder "<<i+1<<" : "<<volume[i]<<"\n";
   	        outputfile<<"Surface area for Cylinder "<<i+1<<" : "<<area[i]<<"\n";
   	        
	   }
}
