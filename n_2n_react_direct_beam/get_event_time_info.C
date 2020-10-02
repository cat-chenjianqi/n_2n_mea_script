#ifndef __CINT__
#include <string>
#include <iostream>
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

void get_event_time_file(TTree* Tree_Result,Int_t detector_section,Int_t Energy_thres, TString N_CHAN_ENERGY, TString D_N_CHAN_TRIGTIME, std::ofstream& outfile2){

   UShort_t N_CHAN_ENERGY_TEMP;
   Double_t D_N_CHAN_TRIGTIME_TEMP;

   Int_t nentries=(Int_t)Tree_Result->GetEntries();
   Tree_Result->SetBranchAddress(D_N_CHAN_TRIGTIME,&D_N_CHAN_TRIGTIME_TEMP);
   Tree_Result->SetBranchAddress(N_CHAN_ENERGY,&N_CHAN_ENERGY_TEMP);

   for (Int_t i=0;i<nentries;i++) {
     Tree_Result->GetEntry(i);
      if (N_CHAN_ENERGY_TEMP>=Energy_thres){
         Tree_Result->GetEntry(i);
         outfile2<<setprecision(15)<<D_N_CHAN_TRIGTIME_TEMP<<" "<<detector_section<<endl;
      }
      else {
       continue;
      }
  }
}

void get_event_time_info()
{
	TString root_file_location="G:\\project\\n_2n_exp_direct_beam\\origin_data\\118\\";
	TString output_file_location="G:\\project\\n_2n_exp_direct_beam\\final_data\\118\\";
	
   TFile *f = new TFile(root_file_location + "test_0118.root");
   TTree *Tree_Result1 = (TTree*)f->Get("Tree_Result1");
   TTree *Tree_Result2 = (TTree*)f->Get("Tree_Result2");
   TTree *Tree_Result3 = (TTree*)f->Get("Tree_Result3");
   TTree *Tree_Result4 = (TTree*)f->Get("Tree_Result4");
   TTree *Tree_Result5 = (TTree*)f->Get("Tree_Result5");
   TTree *Tree_Result6 = (TTree*)f->Get("Tree_Result6");
   TTree *Tree_Result7 = (TTree*)f->Get("Tree_Result7"); 
   TTree *Tree_Result8 = (TTree*)f->Get("Tree_Result8");
   // define the variable time and energy
   Double_t D_N_CHAN_TRIGTIME_1;
   UShort_t N_CHAN_ENERGY_1; //ENERGY-1
   Double_t D_N_CHAN_TRIGTIME_2;
   UShort_t N_CHAN_ENERGY_2; //ENERGY-2
   Double_t D_N_CHAN_TRIGTIME_3;
   UShort_t N_CHAN_ENERGY_3; //ENERGY-3
   Double_t D_N_CHAN_TRIGTIME_4;
   UShort_t N_CHAN_ENERGY_4; //ENERGY-4
   Double_t D_N_CHAN_TRIGTIME_5;
   UShort_t N_CHAN_ENERGY_5; //ENERGY-5
   Double_t D_N_CHAN_TRIGTIME_6;
   UShort_t N_CHAN_ENERGY_6; //ENERGY-6
   Double_t D_N_CHAN_TRIGTIME_7;
   UShort_t N_CHAN_ENERGY_7; //ENERGY-7
   Double_t D_N_CHAN_TRIGTIME_8;
   UShort_t N_CHAN_ENERGY_8; //ENERGY-8
   
   
   Tree_Result1->SetBranchAddress("D_N_CHAN_TRIGTIME_1",&D_N_CHAN_TRIGTIME_1);
   Tree_Result1->SetBranchAddress("N_CHAN_ENERGY_1",&N_CHAN_ENERGY_1);
   Tree_Result2->SetBranchAddress("D_N_CHAN_TRIGTIME_2",&D_N_CHAN_TRIGTIME_2);
   Tree_Result2->SetBranchAddress("N_CHAN_ENERGY_2",&N_CHAN_ENERGY_2);
   Tree_Result3->SetBranchAddress("D_N_CHAN_TRIGTIME_3",&D_N_CHAN_TRIGTIME_3);
   Tree_Result3->SetBranchAddress("N_CHAN_ENERGY_3",&N_CHAN_ENERGY_3);
   Tree_Result4->SetBranchAddress("D_N_CHAN_TRIGTIME_4",&D_N_CHAN_TRIGTIME_4);
   Tree_Result4->SetBranchAddress("N_CHAN_ENERGY_4",&N_CHAN_ENERGY_4);
   Tree_Result5->SetBranchAddress("D_N_CHAN_TRIGTIME_5",&D_N_CHAN_TRIGTIME_5);
   Tree_Result5->SetBranchAddress("N_CHAN_ENERGY_5",&N_CHAN_ENERGY_5);
   Tree_Result6->SetBranchAddress("D_N_CHAN_TRIGTIME_6",&D_N_CHAN_TRIGTIME_6);
   Tree_Result6->SetBranchAddress("N_CHAN_ENERGY_6",&N_CHAN_ENERGY_6);
   Tree_Result7->SetBranchAddress("D_N_CHAN_TRIGTIME_7",&D_N_CHAN_TRIGTIME_7);
   Tree_Result7->SetBranchAddress("N_CHAN_ENERGY_7",&N_CHAN_ENERGY_7);
   Tree_Result8->SetBranchAddress("D_N_CHAN_TRIGTIME_8",&D_N_CHAN_TRIGTIME_8);
   Tree_Result8->SetBranchAddress("N_CHAN_ENERGY_8",&N_CHAN_ENERGY_8);

// retrieve the logical signal time information
   ofstream outfile1;
   outfile1.open(output_file_location+"logical_signal_time_info.dat");
   get_event_time_file(Tree_Result1, 0, 50000, "N_CHAN_ENERGY_1", "D_N_CHAN_TRIGTIME_1", outfile1);
   outfile1.close();
// retrieve the neutron event time information
   ofstream outfile2;
   outfile2.open(output_file_location+"neutron_event_time_info.dat");
   get_event_time_file(Tree_Result2, 1, 1485, "N_CHAN_ENERGY_2", "D_N_CHAN_TRIGTIME_2", outfile2);
   get_event_time_file(Tree_Result3, 2, 795, "N_CHAN_ENERGY_3", "D_N_CHAN_TRIGTIME_3", outfile2);
   get_event_time_file(Tree_Result4, 3, 1505, "N_CHAN_ENERGY_4", "D_N_CHAN_TRIGTIME_4", outfile2);
   get_event_time_file(Tree_Result5, 4, 2235, "N_CHAN_ENERGY_5", "D_N_CHAN_TRIGTIME_5", outfile2);
   get_event_time_file(Tree_Result6, 5, 1675, "N_CHAN_ENERGY_6", "D_N_CHAN_TRIGTIME_6", outfile2);
   get_event_time_file(Tree_Result7, 6, 945, "N_CHAN_ENERGY_7", "D_N_CHAN_TRIGTIME_7", outfile2);
   get_event_time_file(Tree_Result8, 7, 1045, "N_CHAN_ENERGY_8", "D_N_CHAN_TRIGTIME_8", outfile2);
   outfile2.close();

   abort();
}  //end of Wave12r()

void StandaloneApplication(int argc, char** argv) {
  // ==>> here the ROOT macro is called
  get_event_time_info();
}

// This is the standard main of C++ starting a ROOT application
int main(int argc, char** argv) {
   TApplication app("Root Application", &argc, argv);
   StandaloneApplication(app.Argc(), app.Argv());
   app.Run();
   return 0;
}
