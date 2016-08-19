#zPlot Class

This is a class that is designed to handle histograms and TGraphs from analyses using CERN's ROOT tool. The main idea is that all plot/graph objects and the canvases they are stored upon are stored in vectors of each relevant class (TH1, TH2, etc). These objects are then accessible using their names instead of variable names. So if you store a TH1F* object in the TH1* vector, in order to access it you must remember the name and use getTH1("name_of_histogram"). The main advantage of this is that there can be many shared functions for all TH1 functions... so instead of doing:

*make the points circular
*make the points red
*make the lines red
*make the points size 1.0

everytime, you can just say: makeHistPretty() and it can be done. Also, when it comes time to output the plots, instead of having to find all the canvases and make sure they are drawn, you can just say-> makePDF() and all canvases are put into a PDF. The design is to mazimize portability between codes... so instead of re-writing the functions for making nicer plots, you just import the class and use it to manage your histograms.

An example macro is shown in testHist.C.

##Extra Note:
int i=1;
cout << Form("bob_%i",i);
This prints: "bob_1." This can be used as a stand in for an array of histograms, since each one can be given a sequential name. They can all then be recalled with:
for(int i=0;i<maxI;i++) getTH1(Form("bob_%i",i));
