#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

template<class Y>

class Sets
{
    private:
    Y* arr;
    int setsize;

    public:
    Sets()
    {
    	setsize =0;
    }
    Sets(int a)
    {
        setsize=a;
        arr=new Y[setsize];
    }
    
    void getsetelements()
    {
        cout<<"\nEnter the elements of set: ";
        for(int i=0;i<setsize;i++)
        {
            cin>>arr[i];
        }
        Duplicate();
        printSet();
    }
       
    void Duplicate(){
    for(int i=0;i<setsize;i++)
	{
		for(int j=i+1;j<setsize;j++)
		{
			if(arr[i]==arr[j])
			{
			    setsize--;
				for(int k=i;k<setsize;k++)
				{		
				    arr[k]=arr[k+1];
			    }
			    i--;	
		    }
		}
	}

    }
    
    void printSet()
    {
        cout<<"The set is: {";
        if(setsize == 0)
        	cout<<" }";
        else
        	 for(int i=0;i<setsize;i++)
	        {
	            cout<<arr[i]<<((i==setsize-1)?'}':',');
	        }
    }

    int getcardinality()
    {
    	return setsize;
	}

	void showcardinality()
	{
		cout<<"The cardinality of set entered is: "<<getcardinality();
	}

	int changecardinality(int n)
	{
		setsize=n;
		return setsize;
	}

    Sets operator +(Sets obj2)

    {
    	Sets temp(setsize+obj2.getcardinality());
        
        for(int i=0;i<setsize;i++)
        {
           temp.arr[i]=arr[i]; 
            
        }
        int k=0;
        for(int j=setsize;j<temp.getcardinality();j++)
        {
            temp.arr[j]=obj2.arr[k];
            k++;
        }
        
        temp.Duplicate();
        
        return (temp);
    }

    Sets operator *(Sets obj2)
    {
    	
    	int n=(obj2.getcardinality()<setsize)?obj2.getcardinality() : setsize;
    	
    	{
		
    		Sets temp(n);
    		{
			int k=0;
    		for(int i=0;i<obj2.getcardinality();i++)
			{
				for(int j=0;j<setsize;j++)
				{
				  if(obj2.arr[i]==arr[j])
				   	 {
						temp.arr[k++]=obj2.arr[i];
						
				   	 } 
				}
			}
			temp.changecardinality(k);
			temp.Duplicate();
			
			return (temp);
			
        	}
	}
    }
	
	Sets &operator = (const Sets &obj2)
	{
		setsize = obj2.setsize;
		arr = new Y[setsize];
		for(int i=0;i<setsize;i++)
		{
			arr[i]=obj2.arr[i];
		}
		Duplicate();
		return (*this);
	}
 
    Sets operator - (Sets obj2)
    {
    	int n=setsize;
    	int k=0;
    	Sets temp(n);
		for(int i=0;i<setsize;i++)
		{
			int flag=0;
			for(int j=0;j<obj2.getcardinality();j++)
			{
				if(arr[i]==obj2.arr[j])
				{
					flag=1;	
					break;		
				}
				
			}
			if(!flag)
				{
					temp.arr[k++]=arr[i];
				}
		 } 
    
    	temp.Duplicate();
    
    	temp.changecardinality(k);
    	return (temp);
	}

	Sets operator ^ (Sets obj2)
	{
		int n=(obj2.getcardinality()>=setsize)?obj2.getcardinality() : setsize;
		Sets temp1(setsize+obj2.getcardinality());
		Sets temp2(n);
		Sets temp(n);
		temp1=*this +obj2;
		temp2=*this * obj2;
		temp=temp1-temp2;
		temp.Duplicate();
    	return (temp);
	}

	bool operator == (Sets obj2)
	{	
		
		if(setsize==obj2.getcardinality())
		{
			int flag1=0;
		    int flag2=1;
	      	for(int k=0;k<setsize&&flag2;k++)
			{
				flag1=0;
				for(int m=0;m<setsize;m++)
				{	
					if(arr[k]==obj2.arr[m])
			  	  {   
						 flag1=1;	
						 break; 
			   		}
		
				}
				if(flag1==0)
				{
					flag2=0;
				}
		}
		if(flag2)
			return true;
		else
			return false;
		}
		else
		{
			cout<<"\nThe size of both the sets is different ";
			return false;
		}
		
	}

	void genpowerset(int setsize)
	{
		cout<<"The power set is : {";
		for(int i=0;i<pow(2,setsize);i++)
		{
			cout<<"{";
			for(int t=i,j=0;j<setsize;j++)
			{
				if(t&1)
				{
					cout<<arr[j]<<" ";
				}
				t=t>>1;
				
			}
			cout<<"}";
			cout<<((i<pow(2,setsize)-1)?',':'}');
		}
		cout<<"\n";
		cout<<"\nThe cardianality of power set is: "<<pow(2,setsize);	
	}

};


template <typename Y>
void func(Y typeVar)
{

int s,p,choice;
    
        	cout<<"\nEnter size of set A: ";
        	cin>>s;
        	Sets<Y> obj1(s);
       		obj1.getsetelements();
       		
       		cout<<"\nEnter size of set B: ";
       		cin>>p;
        	Sets<Y> obj2(p);
        	obj2.getsetelements();
        	
        	Sets<Y> obj3;	
            cout<<endl;
            
            char ans;
            cout<<endl;
       do
	   {
		cout<<"\nEnter the number to perform following operations: ";
		cout<<"\n";
		cout<<"\n1.Union of two sets";
		cout<<"\n2.Intersection of two sets";
		cout<<"\n3.Difference of two sets";
		cout<<"\n4.Symmetric Difference of two sets";
		cout<<"\n5.Check the equality of two sets";
		cout<<"\n6.Copy values of one set to another";
		cout<<"\n7.Generate power set: ";
		cout<<"\n8.Find cardinality of set.";          
		cout<<endl;
		cout<<"\nEnter the choice: ";
		cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1:
				{
					obj3=obj1+obj2;  
					obj3.printSet();        
					break;
				}
			case 2:
				{
					
					obj3=obj1*obj2;
					obj3.printSet();         
					break;
				}
			case 3:
				{
					obj3=obj1-obj2;
					obj3.printSet();		    
					break;
				}
			case 4:
				{
					obj3=obj1^obj2;	
					obj3.printSet();	
					break;
				}
			case 5:
				{
				 if(obj1==obj2)			
        	   		 cout<<"->The sets are same.";
               	 else
             		cout<<"->The sets are not same";
             		break;
				}
			case 6:
				{
					obj3=obj2;	
					obj3.printSet();					
					break;
				}
			case 7:
				{
					system("CLS");
					cout<<"\n a.Generate power set of set 'A'.(Press a)";
					cout<<"\n b.Generate power set of set 'B'.(Press b)";
					char subchoice;
					cout<<"\nEnter your choice: ";   
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'a':
							{
								int setsize=obj1.getcardinality();
								obj1.genpowerset(setsize);
								break;
					   	    }
							case 'b':
							{
								int setsize=obj2.getcardinality();
								obj2.genpowerset(setsize);
								break;
							}
							default:
							{
								cout<<"Enter correct choice!!!!";
								
							}
							
					    } 
					    break;
	            }
	        case 8:
	        	{
	        		system("CLS");						
					cout<<"\n a.Find cardinality of set 'A'.(Press a)";
					cout<<"\n b.Find cardinality of set 'B'.(Press b)";
					char subchoice;
					cout<<"\nEnter your Response: ";
					cin>>subchoice;
				
						switch(subchoice)
						{
							case 'a':
							{
								obj1.showcardinality();
								
								break;
					   	    }
							case 'b':
							{
								obj2.showcardinality();
								
								break;
							}
							default:
							{
								cout<<"\nEnter correct choice!";
								
							}
							
					    } 
					    break;
				}
	            
	        default:
	            {
	            	cout<<"Enter correct choice!!";
	            	break;
				}
			}
			
			cout<<"\nDo you wish to continue(Press 'Y' for YES and 'N' for NO.)";
			cout<<"\nChoice->";
			cin>>ans;
			cout<<endl;
			 system("CLS");
   	 }
   	
   	 while(ans=='Y'||ans=='y');
   	 
   }

    int main()
    {
      int choice;
   	
   	 cout<<"\nEnter the datatype on which operations are to be performed: ";
   	 cout<<"\n~1.Integers";
 	 cout<<"\n~2.Characters";
	 cout<<"\n~3.Double" ; 
	 cout<<"\nEnter your choice "; 	 
   	 cin>>choice;
   	 
   	 int i;
   	 char c;
   	 double d;
   	 
   	 switch(choice)
   	 {
   	 	case 1: func(i);
   	 		break;
   	 			
		case 2: func(c);
   	 		break;
   	 		
   	 	case 3: func(d);
   	 		break;
   	 	default:
   	 		cout<<"Enter correct choice";
		} 
   	 return 0;
}

