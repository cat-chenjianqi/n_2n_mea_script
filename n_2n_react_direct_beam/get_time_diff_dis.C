#ifndef __CINT__
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TRandom.h>
#include <TCanvas.h>
#include <stdlib.h>
#endif

using namespace std;

void get_time_diff_dis()
{
	TString input_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\118\\";
	TString output_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\118\\";

	ifstream myfile;
	myfile.open(input_file_location+"neutron_event_time_info.dat");
	
	vector<string> vec;
	std::string temp;
	
	TString mark[8];
	mark[0] = "total";
	mark[1] = "detector_section_1";
	mark[2] = "detector_section_2";
	mark[3] = "detector_section_3";
	mark[4] = "detector_section_4";
	mark[5] = "detector_section_5";
	mark[6] = "detector_section_6";
	mark[7] = "detector_section_7";

	TString sample_name[1];
	sample_name[0] = "#bullet Sample: Null";

	while (getline(myfile,temp))
	{
		vec.push_back(temp);
	}

	vector <float> vec_event_time_1, vec_event_time_2, vec_event_time_3;
	vector <float> vec_event_time_4, vec_event_time_5, vec_event_time_6;
	vector <float> vec_event_time_7, vec_event_time_total;
	
	for(auto it = vec.begin(); it != vec.end(); it++)
	{
		istringstream is(*it);
		string event_time, section_num;
		
		is>>event_time>>section_num;

			if(atof(section_num.c_str()) == 1)
			{
				float var_temp_1 = atof(event_time.c_str());
				vec_event_time_1.push_back(var_temp_1);
			}
			else if(atof(section_num.c_str()) == 2)
			{
				float var_temp_2 = atof(event_time.c_str());
				vec_event_time_2.push_back(var_temp_2);
			}
			else if(atof(section_num.c_str()) == 3)
			{
				float var_temp_3 = atof(event_time.c_str());
				vec_event_time_3.push_back(var_temp_3);
			}
			else if(atof(section_num.c_str()) == 4)
			{
				float var_temp_4 = atof(event_time.c_str());
				vec_event_time_4.push_back(var_temp_4);
			}
			else if(atof(section_num.c_str()) == 5)
			{
				float var_temp_5 = atof(event_time.c_str());
				vec_event_time_5.push_back(var_temp_5);
			}
			else if(atof(section_num.c_str()) == 6)
			{
				float var_temp_6 = atof(event_time.c_str());
				vec_event_time_6.push_back(var_temp_6);
			}
			else
			{
				float var_temp_7 = atof(event_time.c_str());
				vec_event_time_7.push_back(var_temp_7);
			}

		float var_temp_total = atof(event_time.c_str());
		vec_event_time_total.push_back(var_temp_total);

	}


	int num_event_time_1 = vec_event_time_1.size();
	sort(&vec_event_time_1[0],&vec_event_time_1[num_event_time_1]);
	int num_event_time_2 = vec_event_time_2.size();
	sort(&vec_event_time_2[0],&vec_event_time_2[num_event_time_2]);
	int num_event_time_3 = vec_event_time_3.size();
	sort(&vec_event_time_3[0],&vec_event_time_3[num_event_time_3]);
	int num_event_time_4 = vec_event_time_4.size();
	sort(&vec_event_time_4[0],&vec_event_time_4[num_event_time_4]);
	int num_event_time_5 = vec_event_time_5.size();
	sort(&vec_event_time_5[0],&vec_event_time_5[num_event_time_5]);
	int num_event_time_6 = vec_event_time_6.size();
	sort(&vec_event_time_6[0],&vec_event_time_6[num_event_time_6]);
	int num_event_time_7 = vec_event_time_7.size();
	sort(&vec_event_time_7[0],&vec_event_time_7[num_event_time_7]);
	int num_event_time_total = vec_event_time_total.size();
	sort(&vec_event_time_total[0],&vec_event_time_total[num_event_time_total]);



	vector <float> vec_time_diff_event_1;
	vector <float> vec_time_diff_event_2;
	vector <float> vec_time_diff_event_3;
	vector <float> vec_time_diff_event_4;
	vector <float> vec_time_diff_event_5;
	vector <float> vec_time_diff_event_6;
	vector <float> vec_time_diff_event_7;
	vector <float> vec_time_diff_event_total;

 
	for(int i=0; i<vec_event_time_1.size()-1; i++)
	{
		vec_time_diff_event_1.push_back(vec_event_time_1[i+1]-vec_event_time_1[i]);
	}
	for(int i=0; i<vec_event_time_2.size()-1; i++)
	{
		vec_time_diff_event_2.push_back(vec_event_time_2[i+1]-vec_event_time_2[i]);
	}
	for(int i=0; i<vec_event_time_3.size()-1; i++)
	{
		vec_time_diff_event_3.push_back(vec_event_time_3[i+1]-vec_event_time_3[i]);
	}
	for(int i=0; i<vec_event_time_4.size()-1; i++)
	{
		vec_time_diff_event_4.push_back(vec_event_time_4[i+1]-vec_event_time_4[i]);
	}
	for(int i=0; i<vec_event_time_5.size()-1; i++)
	{
		vec_time_diff_event_5.push_back(vec_event_time_5[i+1]-vec_event_time_5[i]);
	}
	for(int i=0; i<vec_event_time_6.size()-1; i++)
	{
		vec_time_diff_event_6.push_back(vec_event_time_6[i+1]-vec_event_time_6[i]);
	}
	for(int i=0; i<vec_event_time_7.size()-1; i++)
	{
		vec_time_diff_event_7.push_back(vec_event_time_7[i+1]-vec_event_time_7[i]);
	}
	for(int i=0; i<vec_event_time_total.size()-1; i++)
	{
		vec_time_diff_event_total.push_back(vec_event_time_total[i+1]-vec_event_time_total[i]);
	}


	TH1D* time_dis_1 = new TH1D("time_dis_1","",1000,0,1000);
	TH1D* time_dis_2 = new TH1D("time_dis_2","",1000,0,1000);
	TH1D* time_dis_3 = new TH1D("time_dis_3","",1000,0,1000);
	TH1D* time_dis_4 = new TH1D("time_dis_4","",1000,0,1000);
	TH1D* time_dis_5 = new TH1D("time_dis_5","",1000,0,1000);
	TH1D* time_dis_6 = new TH1D("time_dis_6","",1000,0,1000);
	TH1D* time_dis_7 = new TH1D("time_dis_7","",1000,0,1000);
	TH1D* time_dis_total = new TH1D("time_dis_total","",100,0,100);


	for(int j=0; j<vec_time_diff_event_1.size()-1;j++)
	{
		time_dis_1->Fill(vec_time_diff_event_1[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_2.size()-1;j++)
	{
		time_dis_2->Fill(vec_time_diff_event_2[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_3.size()-1;j++)
	{
		time_dis_3->Fill(vec_time_diff_event_3[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_4.size()-1;j++)
	{
		time_dis_4->Fill(vec_time_diff_event_4[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_5.size()-1;j++)
	{
		time_dis_5->Fill(vec_time_diff_event_5[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_6.size()-1;j++)
	{
		time_dis_6->Fill(vec_time_diff_event_6[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_7.size()-1;j++)
	{
		time_dis_7->Fill(vec_time_diff_event_7[j]*1000);
	}
	for(int j=0; j<vec_time_diff_event_total.size()-1;j++)
	{
		time_dis_total->Fill(vec_time_diff_event_total[j]*1000);
	}


	TCanvas* c2;
	c2 = new TCanvas( "c2", "c2", 1600, 900 );

	c2->Divide(2,4);
	c2->cd(1);
	format_plot_3(time_dis_total,mark[0],sample_name[0]);
 	c2->cd(2);
	format_plot_4(time_dis_1,mark[1]);
	c2->cd(3);
	format_plot_4(time_dis_2,mark[2]);
	c2->cd(4);
	format_plot_4(time_dis_3,mark[3]);
	c2->cd(5);
	format_plot_4(time_dis_4,mark[4]);
	c2->cd(6);
	format_plot_4(time_dis_5,mark[5]);
	c2->cd(7);
	format_plot_4(time_dis_6,mark[6]);
	c2->cd(8);
	format_plot_4(time_dis_7,mark[7]);


	c2->SaveAs( output_file_location + "neutron_event_time_distribution.pdf" );
	c2->SaveAs( output_file_location + "neutron_event_time_distribution.eps" );


/* 	for(auto it = radius.begin();it!=radius.end();it++)
	{
		cout<<*it<<endl;
	} */

}