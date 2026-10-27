# Formula sheet — all ten units

No derivations. RMS/average factors: $V_{rms}=V_m/\sqrt2=0.707V_m$, $V_{avg}=2V_m/\pi=0.637V_m$.

## 1 — DC fundamentals
$$V = IR \qquad P = VI = I^2R = \frac{V^2}{R} \qquad W = Pt \;(\text{kWh})$$
$$R = \frac{\rho l}{A} \qquad R_t = R_0\,[1+\alpha(t-t_0)]$$
Series: $R = R_1+R_2+\dots$   Parallel: $\dfrac{1}{R}=\dfrac{1}{R_1}+\dfrac{1}{R_2}+\dots$, two: $R=\dfrac{R_1R_2}{R_1+R_2}$
KCL: $\sum I_{node}=0$.  KVL: $\sum V_{loop}=0$.
Divider: $V_1=V\dfrac{R_1}{R_1+R_2}$,  $I_1=I\dfrac{R_2}{R_1+R_2}$.

## 2 — Network theorems
Thevenin: $I_L=\dfrac{V_{th}}{R_{th}+R_L}$.  Norton: $I_N=\dfrac{V_{th}}{R_{th}}$, $R_N=R_{th}$.
Source transform: $V=IR$.  Superposition: sum the responses of each source alone.
Max power transfer: $R_L=R_{th}$, $P_{max}=\dfrac{V_{th}^2}{4R_{th}}$.

## 3 — AC fundamentals
$$v=V_m\sin\omega t \qquad \omega=2\pi f \qquad f=\frac{1}{T}$$
$$V_{rms}=\frac{V_m}{\sqrt2} \qquad V_{avg}=\frac{2V_m}{\pi} \qquad
\text{form factor}=\frac{V_{rms}}{V_{avg}}=1.11 \qquad \text{peak factor}=\frac{V_m}{V_{rms}}=1.414$$

## 4 — Single-phase AC
$$X_L=2\pi fL \qquad X_C=\frac{1}{2\pi fC} \qquad Z=\sqrt{R^2+(X_L-X_C)^2} \qquad \phi=\tan^{-1}\frac{X}{R}$$
$$\cos\phi=\frac{R}{Z} \qquad P=VI\cos\phi \qquad Q=VI\sin\phi \qquad S=VI=\sqrt{P^2+Q^2}$$
Series resonance: $f_r=\dfrac{1}{2\pi\sqrt{LC}}$, $X_L=X_C$, $Z=R$ (min), $I$ max.
$$Q\text{-factor}=\frac{\omega_r L}{R}=\frac{1}{\omega_r CR}=\frac{1}{R}\sqrt{\frac{L}{C}} \qquad BW=\frac{f_r}{Q}$$

## 5 — Three-phase systems
Star: $V_L=\sqrt3\,V_{ph}$, $I_L=I_{ph}$.  Delta: $V_L=V_{ph}$, $I_L=\sqrt3\,I_{ph}$.
$$P=\sqrt3\,V_L I_L\cos\phi \qquad Q=\sqrt3\,V_L I_L\sin\phi \qquad S=\sqrt3\,V_L I_L$$
Two-wattmeter: $P=W_1+W_2$,  $\tan\phi=\sqrt3\,\dfrac{W_1-W_2}{W_1+W_2}$.

## 6 — Transformers
$$E=4.44\,f\,N\,\Phi_m \qquad \frac{E_1}{E_2}=\frac{N_1}{N_2}=\frac{I_2}{I_1}=a$$
$$\eta=\frac{P_{out}}{P_{out}+P_i+P_{cu}} \qquad P_{cu}(x)=x^2P_{cu,FL}$$
Max $\eta$ when $P_{cu}=P_i$, at load fraction $x=\sqrt{P_i/P_{cu,FL}}$.
Regulation: $\%VR=\dfrac{E_2-V_2}{V_2}\times100$.

## 7 — DC machines
$$E=\frac{P\Phi ZN}{60A} \qquad \text{(gen) } V=E-I_aR_a \qquad \text{(motor) } E_b=V-I_aR_a$$
$$T_a=\frac{P\Phi Z I_a}{2\pi A}\;\propto\;\Phi I_a \qquad T=\frac{60P}{2\pi N}=9.55\frac{P}{N} \qquad N\propto\frac{E_b}{\Phi}$$
Shunt: $I_{sh}=V/R_{sh}$, $I_a=I_L\pm I_{sh}$.  Series: $I_a=I_{se}=I_L$.

## 8 — AC machines
$$N_s=\frac{120f}{P} \qquad s=\frac{N_s-N}{N_s} \qquad N=N_s(1-s)$$
$$f_r=sf \qquad E_r=sE_2 \qquad X_r=sX_2 \qquad T\propto\frac{sE_2^2R_2}{R_2^2+(sX_2)^2}$$
Max torque at $s=R_2/X_2$.

## 9 — Measuring instruments
PMMC $\theta\propto I$;  MI $\theta\propto I^2$.
$$R_{sh}=\frac{I_gR_g}{I-I_g},\; n=\frac{I}{I_g}=1+\frac{R_g}{R_{sh}} \qquad
R_s=\frac{V}{I_g}-R_g,\; m=\frac{V}{I_gR_g}=1+\frac{R_s}{R_g}$$
Wattmeter $P=VI\cos\phi$.  Error $e=A_m-A_t$, $\%\text{err}=\dfrac{e}{A_t}\times100$.

## 10 — Wiring and safety
$$\text{units (kWh)}=\frac{\sum(W\times h/\text{day}\times \text{qty})\times \text{days}}{1000}$$
$$I=\frac{P}{V\cos\phi}\;(1\phi) \qquad I=\frac{P}{\sqrt3\,V_L\cos\phi}\;(3\phi) \qquad
R_{earth}=\frac{\rho}{2\pi L}\ln\frac{4L}{d}$$
Fusing factor $=\dfrac{\text{fusing current}}{\text{rated current}}$.  Bill $=$ fixed charge $+\sum(\text{slab units}\times\text{rate})$.
