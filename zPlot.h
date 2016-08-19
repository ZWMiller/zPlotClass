#ifndef zPlot_h
#define zPlot_h

class zPlot {
  
  public:
    zPlot();
    zPlot(TString anaTitle, TString outName);
    virtual ~zPlot();

    void addTH1(TString,TString,int,int,int);
    void addTH1(TH1*);
    void addTH2(TString,TString,int,int,int,int,int,int);
    void addTH2(TH2*);
    void addTH3(TString,TString,int,int,int,int,int,int,int,int,int);
    void addTH3(TH3*);
    void addCanvas(TString,TString);
    void clearHistVectors();
    void makePDF();

    TH1* getTH1(TString);
    TH2* getTH2(TString);
    TH3* getTH3(TString);
    TCanvas* getCanvas(TString);
    TGraph* getTGraph(TString);

    void plotTH1(TString,TString,int i=0,TString opt="pe");
    void plotTH2(TString,TString,int,TString);
    void plotTH3(TString,TString,int,TString);

    void pretty1DHist(TString, int, int);
    void pretty1DHistFill(TString, int, int);
    void prettyTGraph(TGraphErrors*, int, int, float, float);
    void prettyTGraph(TGraph*, int, int, float, float);

    void fillTH1(TString,float,float weight=1.);
    void fillTH2(TString,float,float,float weight=1.);
    void fillTH3(TString,float,float,float,float weight=1.);

    const int colors[5] = {kBlack,kRed,kAzure+1,kMagenta,kGreen+3};
  protected: 
    std::vector<TH1*> th1;
    std::vector<TH2*> th2;
    std::vector<TH3*> th3;
    std::vector<TGraph*> tgraph;
    std::vector<TCanvas*> tcanvas;
  private:
    TString analysisTitle;
    TString outfileName;
    void makeFrontPage();
};
#endif
