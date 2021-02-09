#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

vector<pair<int,int> > pos; //container for value x and y
int tc = 0;
double VCC,VCE,VBE,RB,RC,IC,IB,IE,PE,Bdc,adc,IDSS,I,VGS,VP,ID;

///gen_valuex_valuey_BJT start here ****************************************************************************************

int gen_valuex_valuey_BJT()
{
    int vbe,vr,I;
//    cout<<"please enter the value of Vr>4"<<endl;
    vr=5;
//    cout<<"please enter the value of I where I>>Vr"<<endl;
    I=20;
    //initializer
    //double xx,yy;
    //xx = 0,yy=0;
    pos.push_back(make_pair(0,0));
    pos.push_back(make_pair(4*10,1*10));
    pos.push_back(make_pair(vr*10,I*10));
    tc = 3;
}

/// gen _valuex_valuey_JEFT start here *******************************************************************************************

int gen_valuex_valuey_jFET()
{
    int vbe,vr,I;
    cout<<"please enter the value Vp"<<endl;
    cin>>vr;
    //initializer
    //double xx,yy;
    //xx = 0,yy=0;
    pos.push_back(make_pair(0,0));
    pos.push_back(make_pair(4*10,10*10));
    tc = 3;
    if(vr<=16) pos.push_back(make_pair((4+vr)*10,10*10));
    else
    {
        pos.push_back(make_pair((4+16)*10,10*10));
        pos.push_back(make_pair((4+16)*10,15*10));
        tc = 4;
    }
}


int gen_valuex_valuey_MOSFET()
{
    int vbe,vr,I;
    cout<<"please enter the value Vp"<<endl;
    cin>>vr;
    //initializer
    //double xx,yy;
    //xx = 0,yy=0;
    pos.push_back(make_pair(0,0));
    pos.push_back(make_pair(4*10,10*10));
    tc = 3;
    if(vr<=16) pos.push_back(make_pair((4+vr)*10,10*10));
    else
    {
        pos.push_back(make_pair((4+16)*10,10*10));
        pos.push_back(make_pair((4+16)*10,15*10));
        tc = 4;
    }
}


/// graph start here **********************************************************************************************************************
int graph()
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // code goes here

    int  x1, y1, x2, y2;

    // root co ordinate of first line == root x :
    // line position from main screen
    int first_x1 = 0;
    int first_y1 = 250;
    int first_x2 = 700;
    int first_y2 = 250;

    line(first_x1, first_y1, first_x2, first_y2); // x - axis
    // root co ordinate of second line == root y :
    //line position from main screen
    int secon_x1 = 300;
    int secon_y1 = 0;
    int secon_x2 = 300;
    int secon_y2 = 500;

    line(secon_x1, secon_y1, secon_x2, secon_y2); // y - axis

    //now taking points of circles //

    int x, y;

    // (x,y) == (0, 0) in graph
    x = 300;
    y = 250;

    int xx = x; // taking temporary variables //
    int yy = y;

    int radius = 3; // radius of the circle ... which will indicate the points of x1, y1

    // cin >> tc;
    for(int i=0; i<tc; i++)
    {
        x1 = 0;
        y1 = 0;
        ///double_to_int(&x1, &y1);
        //cin >> x1 >> y1;
        //3cout << x1 << " " << y1 << endl;
        x1 = pos[i].first;
        y1 = pos[i].second;
        cout<<x1<<" "<<y1<<endl;
        x1 = x + x1; // (x1,y1) circle point taking (x, y) as zero point //
        y1 = y - y1;
        circle(x1, y1, radius); // printing circles == point in graph

        // now connecting two points and making a line //
        line(xx, yy, x1, y1);
        // now we will make x1, y1 as the point of the first line
        xx = x1;
        yy = y1;
    }
    pos.clear();

    // code ends here
    //getch();
    closegraph();
    return 0;
}

/// BJT start here //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void equation_BJT()
{
    cout<<"Enter the value of V(BE) : "<<endl;
    cin>>VBE;
    cout<<"Enter the value of V(CC) : "<<endl;
    cin>>VCC;
    cout<<"Enter the value of R(B) : "<<endl;
    cin>>RB;
    cout<<"Enter the value of R(C) : "<<endl;
    cin>>RC;
    IB=abs((VCC-VBE)/RB);
    cout<<"I(B) = "<<IB<<endl;
    cout<<"Enter the value of @(dc) : "<<endl;
    cin>>adc;
    Bdc=abs(adc/(1-adc));
    cout<<"B(dc) = "<<Bdc<<endl;
    IC=abs(Bdc*IB);
    cout<<"I(C) = "<<IC<<endl;
    IE=abs(IC+IB);
    cout<<"I(E) = "<<IE<<endl;
    VCE=VCC-IC*RC;
    cout<<" V(CE) = "<<VCE<<endl;
    PE=VCE*IC;
    cout<<"P(E) = "<<PE<<endl;
}

int BJT()
{
    fstream myfile;
    //file start
    myfile.open("BJT.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    //file end
    char s;
    cin>>s;
    if(s=='Y' || s=='y')
    {
        gen_valuex_valuey_BJT();
        graph();
    }
    else if(s=='Z' || s=='z')
    {
        equation_BJT();
    }
    else return 0;


}
void equation_JFET()
{

    cout<<"Enter the value of I = "<<endl;
    cin>>I;
    cout<<"Enter the value of V(GS) = "<<endl;
    cin>>VGS;
    cout<<"Enter the value of V(P) = "<<endl;
    cin>>VP;
    cout<<"Enter the value of I(DSS) : "<<endl;
    cin>>IDSS;
    ID=(I-(VGS/VP))*(I-(VGS/VP))*IDSS;
    cout<<"ID = "<<ID<<endl;
}

int jFET()
{
    fstream myfile;
    //file start
    myfile.open("JFET.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    //file end
    char s;
    cin>>s;
    if(s=='Y' || s=='y')
    {
        gen_valuex_valuey_jFET();
        graph();
    }
    else if(s=='Z' || s=='z')
    {
        equation_JFET();
    }
    else return 0;


}

int MOSFET()
{
    fstream myfile;
    //file start
    myfile.open("MOSFET.txt");
    string line;
    while(getline(myfile,line))
    {
        cout<<line<<endl;
    }
    myfile.close();
    //file end
    char s;
    cin>>s;
    if(s=='Y' || s=='y')
    {
        gen_valuex_valuey_jFET();
        graph();
    }
    else return 0;


}



///HOME start here //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Home()
{
    cout<<"Chose from following one: "<<endl;
    cout<<"1. BJT"<<endl;
    cout<<"2. jFET"<<endl;
    cout<<"3. MOSFET"<<endl;
    cout<<endl<<"Press 4 to quit"<<endl;
    int s;
    cin>>s;
    system("cls");
    return s;

}


///main start here ************************************************************************************************************

int main()
{
    //start here
    int  x = 5;
    while(x!=4)
    {
        x = Home();
        if(x==1) BJT();
        else if(x==2)jFET();
        else if(x==3)MOSFET();
        // cout<<x<<endl;
    }
}
