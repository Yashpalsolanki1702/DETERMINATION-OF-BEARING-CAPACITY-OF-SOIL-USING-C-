#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double c,phi;
    cout<<"Input value of c: ";
    cin>>c;
    cout<<"Input value of phi: ";
    cin>>phi;
    double deg=M_PI/180;
    double phi_d=phi/2;
    phi=phi*deg;
    phi_d=deg*phi_d;
    double N_phi=tan(45*deg+ (phi_d));
    N_phi=N_phi*N_phi;
    double N_q=N_phi*exp(M_PI*tan(phi));
    cout<<"N_q "<<N_q<<endl;
    double N_gamma=2*(tan(phi))*(N_q +1);
    double N_c = (1/tan(phi))*(N_q -1);
    cout<<"N_c"<<N_c<<endl;
    cout<<"N_gamma"<<N_gamma<<endl;
    string s;
    cout<<"Input type of footing: ";
	cin>>s;
    
    double s_c,s_q,s_gamma;
    double b,gamma,w,d,alpha;
    cout<<"Input value of b:";
    cin>>b;
    
    cout<<"Input value of gamma:";
    cin>>gamma;
	
	cout<<"Input value of w:";
    cin>>w;
	
	cout<<"Input value of d:";
    cin>>d;
	
	cout<<"Input value of alpha:";
	cin>>alpha;
//    cin>>b>>gamma>>w>>d>>alpha;
    double q=gamma*d;
    double qu;
    if(s=="strip"){
        s_c=1.00;
        s_q=1.00;
        s_gamma=1.00;}
    else if(s=="rectangle"){
        double b,l;
        cout<<"Input value of b:";
        cin>>b;
        cout<<"Input value of l:";
        cin>>l;
		s_c=1+0.2*(double (b)/double (l));
        s_q=1+0.2*(double (b)/double (l));
        s_gamma=1-0.4*(double (b)/double (l));
    }
    else if(s=="square"){
        s_c=1.30;
        s_q=1.20;
        s_gamma=0.80;
    }
    else if(s=="circle"){
        s_c=1.30;
        s_q=1.20;
        s_gamma=0.60;
    }
//    cout<<s_c<<" "<<s_q<<" "<<s_gamma<<endl;
    double dc,ic,dq,iq,d_gamma,i_gamma;
    dc=(1+0.2*(d/b)*sqrt(N_phi));
    dq=(1+0.1*(d/b)*sqrt(N_phi));
    d_gamma=dq;
    ic=pow((1-(alpha/90)),2);
    iq=ic;
    i_gamma=pow((1-(alpha/(phi/deg))),2);
//    cout<<dc<<" "<<dq<<" "<<d_gamma<<" "<<ic<<" "<<iq<<" "<<i_gamma<<endl;
    if(phi<28*deg){
        if(phi<10*deg){dq=1;d_gamma=1;}
    
    qu= ((c*N_c*s_c*dc*ic))+(q*(N_q-1)*s_q*dq*iq)+(b*gamma*N_gamma*s_gamma*d_gamma*i_gamma*w/(2.0));

   	
    }
    else if(phi>=28*deg and phi<36*deg){
        
		double qu_l = ((c*N_c*s_c*dc*ic))+(q*(N_q-1)*s_q*dq*iq)+(b*gamma*N_gamma*s_gamma*d_gamma*i_gamma*w/(2.0));

		double qu_u =(c*N_c*s_c*dc*ic)+(q*(N_q-1)*s_q*dq*iq)+(b*gamma*N_gamma*s_gamma*d_gamma*i_gamma*w/(2.0));
		
		qu= qu_l*((phi/deg -28)/(36-28)) + qu_u*((36-phi/deg)/(36-28));
    }
    else
    {
    	qu=(c*N_c*s_c*dc*ic)+(q*(N_q-1)*s_q*dq*iq)+(b*gamma*N_gamma*s_gamma*d_gamma*i_gamma*w/(2.0));
	}
	
	double f;
	cout<<"input value of f: ";
	cin>>f;
	double qs;
	
		
	qs = (qu/f) + (gamma*d)	;
	 cout<<"net ultimate bearing capacity of soil: "<<qu<<endl;
	 cout<<"safe bearing capacity of soil: "<<qs<<endl;
    
	return 0;
}

