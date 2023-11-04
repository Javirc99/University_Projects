<Qucs Schematic 2.1.0>
<Properties>
  <View=-71,140,2252,1294,0.683014,29,0>
  <Grid=10,10,1>
  <DataSet=lowpass.dat>
  <DataDisplay=lowpass.dpl>
  <OpenDisplay=0>
  <Script=lowpass.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Título>
  <FrameText1=Dibujado por:>
  <FrameText2=Fecha:>
  <FrameText3=Revisión:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 460 470 0 0 0 0>
  <.AC AC1 1 370 560 0 48 0 0 "lin" 1 "1 kHz" 1 "1 Ghz" 1 "50" 1 "no" 0>
  <NutmegEq NutmegEq1 1 680 620 -34 19 0 0 "ac" 1 "TF=20*log10(abs(V(out)/V(In)))" 1>
  <R R1 1 290 190 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <C C1 1 460 270 17 -26 0 1 "1 pF" 1 "" 0 "neutral" 0>
  <GND * 1 140 470 0 0 0 0>
  <Vac V1 1 140 340 18 -26 0 1 "1 V" 1 "200 Mhz" 1 "0" 0 "0" 0>
  <.TR TR1 1 170 550 0 81 0 0 "lin" 1 "0" 1 "10 ns" 1 "50" 1 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
</Components>
<Wires>
  <320 190 460 190 "out" 410 160 57 "">
  <460 190 460 240 "" 0 0 0 "">
  <460 300 460 470 "" 0 0 0 "">
  <140 370 140 470 "" 0 0 0 "">
  <140 190 260 190 "in" 230 160 54 "">
  <140 190 140 310 "" 0 0 0 "">
</Wires>
<Diagrams>
  <Rect 480 1070 240 160 3 #c0c0c0 1 10 1 0 2e+08 1e+09 1 -20 10 1.60722 1 -1 1 1 315 0 225 0 0 0 "" "" "">
	<"ngspice/ac.tf" #0000ff 0 3 0 0 0>
	  <Mkr 1.63266e+08 260 -197 3 0 0>
  </Rect>
  <Rect 120 1080 240 160 3 #c0c0c0 1 00 1 0 0.2 1 1 -0.1 0.5 1.1 1 -0.1 0.5 1.1 315 0 225 0 0 0 "" "" "">
	<"ngspice/tran.v(out)" #0000ff 0 3 0 0 0>
	<"ngspice/tran.v(in)" #ff0000 0 3 0 0 0>
  </Rect>
</Diagrams>
<Paintings>
</Paintings>
