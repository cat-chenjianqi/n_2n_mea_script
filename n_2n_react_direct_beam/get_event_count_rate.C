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
// #include <cmath>
#endif

using namespace std;

float round_new(float var)
{
	float value = int (var*100+0.5);
	return (float) value/100;
}

void get_event_count_rate()
{
	TString input_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\120\\";
	TString output_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\120\\";

	ifstream myfile;
	myfile.open(input_file_location+"neutron_event_time_info.dat");
	
	vector<string> vec;
	std::string temp;
	
	std::ostringstream streamObj_total;
	streamObj_total<<std::fixed;
	streamObj_total<<std::setprecision(2);
	std::ostringstream streamObj_1;
	streamObj_1<<std::fixed;
	streamObj_1<<std::setprecision(2);
	std::ostringstream streamObj_2;
	streamObj_2<<std::fixed;
	streamObj_2<<std::setprecision(2);
	std::ostringstream streamObj_3;
	streamObj_3<<std::fixed;
	streamObj_3<<std::setprecision(2);
	std::ostringstream streamObj_4;
	streamObj_4<<std::fixed;
	streamObj_4<<std::setprecision(2);
	std::ostringstream streamObj_5;
	streamObj_5<<std::fixed;
	streamObj_5<<std::setprecision(2);
	std::ostringstream streamObj_6;
	streamObj_6<<std::fixed;
	streamObj_6<<std::setprecision(2);
	std::ostringstream streamObj_7;
	streamObj_7<<std::fixed;
	streamObj_7<<std::setprecision(2);

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
	sample_name[0] = "#bullet Sample: null";

	int run_time = 3600;

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

	TH1D* time_dis_1 = new TH1D("time_dis_1","",run_time,0,run_time);
	TH1D* time_dis_2 = new TH1D("time_dis_2","",run_time,0,run_time);
	TH1D* time_dis_3 = new TH1D("time_dis_3","",run_time,0,run_time);
	TH1D* time_dis_4 = new TH1D("time_dis_4","",run_time,0,run_time);
	TH1D* time_dis_5 = new TH1D("time_dis_5","",run_time,0,run_time);
	TH1D* time_dis_6 = new TH1D("time_dis_6","",run_time,0,run_time);
	TH1D* time_dis_7 = new TH1D("time_dis_7","",run_time,0,run_time);
	TH1D* time_dis_total = new TH1D("time_dis_total","",run_time,0,run_time);


	for(int j=0; j<vec_event_time_1.size()-1;j++)
	{
		time_dis_1->Fill(vec_event_time_1[j]);
	}
	for(int j=0; j<vec_event_time_2.size()-1;j++)
	{
		time_dis_2->Fill(vec_event_time_2[j]);
	}
	for(int j=0; j<vec_event_time_3.size()-1;j++)
	{
		time_dis_3->Fill(vec_event_time_3[j]);
	}
	for(int j=0; j<vec_event_time_4.size()-1;j++)
	{
		time_dis_4->Fill(vec_event_time_4[j]);
	}
	for(int j=0; j<vec_event_time_5.size()-1;j++)
	{
		time_dis_5->Fill(vec_event_time_5[j]);
	}
	for(int j=0; j<vec_event_time_6.size()-1;j++)
	{
		time_dis_6->Fill(vec_event_time_6[j]);
	}
	for(int j=0; j<vec_event_time_7.size()-1;j++)
	{
		time_dis_7->Fill(vec_event_time_7[j]);
	}
	for(int j=0; j<vec_event_time_total.size()-1;j++)
	{
		time_dis_total->Fill(vec_event_time_total[j]);
	}

	streamObj_total<<time_dis_total->GetEntries()/run_time;
	streamObj_1<<time_dis_1->GetEntries()/run_time;
	streamObj_2<<time_dis_2->GetEntries()/run_time;
	streamObj_3<<time_dis_3->GetEntries()/run_time;
	streamObj_4<<time_dis_4->GetEntries()/run_time;
	streamObj_5<<time_dis_5->GetEntries()/run_time;
	streamObj_6<<time_dis_6->GetEntries()/run_time;
	streamObj_7<<time_dis_7->GetEntries()/run_time;

	TString cout_rate_total = "count rate = "+streamObj_total.str()+" cps";
	TString cout_rate_1 = "count rate = "+streamObj_1.str()+" cps";
	TString cout_rate_2 = "count rate = "+streamObj_2.str()+" cps";
	TString cout_rate_3 = "count rate = "+streamObj_3.str()+" cps";
	TString cout_rate_4 = "count rate = "+streamObj_4.str()+" cps";
	TString cout_rate_5 = "count rate = "+streamObj_5.str()+" cps";
	TString cout_rate_6 = "count rate = "+streamObj_6.str()+" cps";
	TString cout_rate_7 = "count rate = "+streamObj_7.str()+" cps";

	// cout<<"cout_rate_total = "<<to_string(cout_rate_total)<<endl;


	TCanvas* c2;
	c2 = new TCanvas( "c2", "c2", 1600, 900 );

	c2->Divide(2,4);
	c2->cd(1);
	format_plot_5(time_dis_total,mark[0],sample_name[0],cout_rate_total);
	c2->cd(2);
	format_plot_6(time_dis_1,mark[1],cout_rate_1);
	c2->cd(3);
	format_plot_6(time_dis_2,mark[2],cout_rate_2);
	c2->cd(4);
	format_plot_6(time_dis_3,mark[3],cout_rate_3);
	c2->cd(5);
	format_plot_6(time_dis_4,mark[4],cout_rate_4);
	c2->cd(6);
	format_plot_6(time_dis_5,mark[5],cout_rate_5);
	c2->cd(7);
	format_plot_6(time_dis_6,mark[6],cout_rate_6);
	c2->cd(8);
	format_plot_6(time_dis_7,mark[7],cout_rate_7);


	c2->SaveAs( output_file_location + "neutron_event_time_distribution.pdf" );
	c2->SaveAs( output_file_location + "neutron_event_time_distribution.eps" );


/* 	for(auto it = radius.begin();it!=radius.end();it++)
	{
		cout<<*it<<endl;
	} */

}