#include "zPlot.h"
#include "zPlot.cxx"

void testHist()
{
  zPlot* zP = new zPlot("Analysis Test","testFile");
  zP->addTH1("test","Random Test;x;y",1000,-1,1);
  zP->addCanvas("can","test");

  gRandom->SetSeed();
  float x;
  for(int i=0; i<10000; i++)
  {
    x = gRandom->Gaus(0,0.3);
    zP->fillTH1("test",x);
  }

  zP->plotTH1("test",zP->getCanvas("can"));
  zP->pretty1DHist("test",zP->colors[0],20);
  zP->getTH1("test")->Fit("gaus");
  zP->makePDF();
}
