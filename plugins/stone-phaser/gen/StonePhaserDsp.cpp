
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: stone_phaser.dsp
// Name: Stone Phaser
// Author: Jean Pierre Cimalando
// Copyright: 
// License: CC0-1.0 or BSL-1.0
// Version: 1.2.2
//------------------------------------------------------------------------------







#include "StonePhaserDsp.hpp"



#include <utility>
#include <cmath>

class StonePhaserDsp::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef StonePhaserDsp::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

class mydspSIG0 {
	
  FAUSTPP_PRIVATE:
	
	int iRec15[2];
	
  public:
	
	int getNumInputsmydspSIG0() {
		return 0;
	}
	int getNumOutputsmydspSIG0() {
		return 1;
	}
	int getInputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	int getOutputRatemydspSIG0(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	void instanceInitmydspSIG0(int sample_rate) {
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			iRec15[l10] = 0;
		}
	}
	
	void fillmydspSIG0(int count, float* table) {
		for (int i = 0; (i < count); i = (i + 1)) {
			iRec15[0] = (iRec15[1] + 1);
			float fTemp0 = (0.0078125f * float((iRec15[0] + -1)));
			float fTemp1 = float(int(fTemp0));
			float fTemp2 = (fTemp0 - fTemp1);
			table[i] = (1.0f - (1.02564108f * std::sin((2.69344211f * ((fTemp2 < 0.5f) ? fTemp2 : (fTemp1 + (1.0f - fTemp0)))))));
			iRec15[1] = iRec15[0];
		}
	}

};

static mydspSIG0* newmydspSIG0() { return (mydspSIG0*)new mydspSIG0(); }
static void deletemydspSIG0(mydspSIG0* dsp) { delete dsp; }

static float ftbl0mydspSIG0[128];

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSampleRate;
	float fConst0;
	float fConst1;
	float fConst2;
	FAUSTFLOAT fHslider0;
	float fRec0_perm[4];
	float fConst3;
	float fRec6_perm[4];
	float fConst4;
	FAUSTFLOAT fHslider1;
	float fRec8_perm[4];
	FAUSTFLOAT fHslider2;
	float fRec7_perm[4];
	FAUSTFLOAT fHslider3;
	float fRec10_perm[4];
	float fConst5;
	float fRec9_perm[4];
	float fRec11_perm[4];
	float fRec12_perm[4];
	FAUSTFLOAT fHslider4;
	float fRec14_perm[4];
	float fRec13_perm[4];
	float fConst6;
	float fConst7;
	float fConst8;
	float fRec5_perm[4];
	float fRec4_perm[4];
	float fRec3_perm[4];
	float fRec2_perm[4];
	float fRec1_perm[4];
	float fRec16_perm[4];
	FAUSTFLOAT fCheckbox0;
	float fRec17_perm[4];
	FAUSTFLOAT fHbargraph0;
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("author", "Jean Pierre Cimalando");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("filename", "stone_phaser.dsp");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("license", "CC0-1.0 or BSL-1.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "Stone Phaser");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "0.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "1.2.2");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 1;
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 1;
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 0;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
		mydspSIG0* sig0 = newmydspSIG0();
		sig0->instanceInitmydspSIG0(sample_rate);
		sig0->fillmydspSIG0(128, ftbl0mydspSIG0);
		deletemydspSIG0(sig0);
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		fConst1 = std::exp((0.0f - (10.0f / fConst0)));
		fConst2 = (1.0f - fConst1);
		fConst3 = std::exp((0.0f - (207.345108f / fConst0)));
		fConst4 = (0.00999999978f * fConst2);
		fConst5 = (1.0f / fConst0);
		fConst6 = (0.5f * (fConst3 + 1.0f));
		fConst7 = (0.0f - fConst6);
		fConst8 = (2764.60156f / fConst0);
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(50.0f);
		fHslider1 = FAUSTFLOAT(75.0f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(500.0f);
		fHslider4 = FAUSTFLOAT(0.20000000000000001f);
		fCheckbox0 = FAUSTFLOAT(0.0f);
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 4); l0 = (l0 + 1)) {
			fRec0_perm[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 4); l1 = (l1 + 1)) {
			fRec6_perm[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 4); l2 = (l2 + 1)) {
			fRec8_perm[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 4); l3 = (l3 + 1)) {
			fRec7_perm[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 4); l4 = (l4 + 1)) {
			fRec10_perm[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 4); l5 = (l5 + 1)) {
			fRec9_perm[l5] = 0.0f;
		}
		for (int l6 = 0; (l6 < 4); l6 = (l6 + 1)) {
			fRec11_perm[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 4); l7 = (l7 + 1)) {
			fRec12_perm[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 4); l8 = (l8 + 1)) {
			fRec14_perm[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 4); l9 = (l9 + 1)) {
			fRec13_perm[l9] = 0.0f;
		}
		for (int l11 = 0; (l11 < 4); l11 = (l11 + 1)) {
			fRec5_perm[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 4); l12 = (l12 + 1)) {
			fRec4_perm[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 4); l13 = (l13 + 1)) {
			fRec3_perm[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 4); l14 = (l14 + 1)) {
			fRec2_perm[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 4); l15 = (l15 + 1)) {
			fRec1_perm[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 4); l16 = (l16 + 1)) {
			fRec16_perm[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 4); l17 = (l17 + 1)) {
			fRec17_perm[l17] = 0.0f;
		}
	}
	
	FAUSTPP_VIRTUAL void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	FAUSTPP_VIRTUAL void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSampleRate;
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Stone Phaser");
		ui_interface->declare(&fCheckbox0, "0", "");
		ui_interface->declare(&fCheckbox0, "symbol", "bypass");
		ui_interface->addCheckButton("Bypass", &fCheckbox0);
		ui_interface->declare(&fHslider2, "1", "");
		ui_interface->declare(&fHslider2, "boolean", "");
		ui_interface->declare(&fHslider2, "symbol", "color");
		ui_interface->addHorizontalSlider("Color", &fHslider2, 1.0f, 0.0f, 1.0f, 1.0f);
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "scale", "log");
		ui_interface->declare(&fHslider4, "symbol", "lfo_frequency");
		ui_interface->declare(&fHslider4, "unit", "Hz");
		ui_interface->addHorizontalSlider("LFO frequency", &fHslider4, 0.200000003f, 0.00999999978f, 5.0f, 0.00999999978f);
		ui_interface->declare(&fHslider1, "3", "");
		ui_interface->declare(&fHslider1, "integer", "");
		ui_interface->declare(&fHslider1, "symbol", "feedback_depth");
		ui_interface->declare(&fHslider1, "unit", "%");
		ui_interface->addHorizontalSlider("Feedback depth", &fHslider1, 75.0f, 0.0f, 99.0f, 1.0f);
		ui_interface->declare(&fHslider3, "4", "");
		ui_interface->declare(&fHslider3, "abbrev", "Fb bass cut");
		ui_interface->declare(&fHslider3, "scale", "log");
		ui_interface->declare(&fHslider3, "symbol", "feedback_hpf_cutoff");
		ui_interface->declare(&fHslider3, "unit", "Hz");
		ui_interface->addHorizontalSlider("Feedback bass cut", &fHslider3, 500.0f, 10.0f, 5000.0f, 1.0f);
		ui_interface->declare(&fHslider0, "5", "");
		ui_interface->declare(&fHslider0, "integer", "");
		ui_interface->declare(&fHslider0, "symbol", "mix");
		ui_interface->declare(&fHslider0, "unit", "%");
		ui_interface->addHorizontalSlider("Dry/wet mix", &fHslider0, 50.0f, 0.0f, 100.0f, 1.0f);
		ui_interface->declare(&fHbargraph0, "7", "");
		ui_interface->declare(&fHbargraph0, "symbol", "bypass_meter");
		ui_interface->addHorizontalBargraph("Bypass meter", &fHbargraph0, 0.0f, 1.0f);
		ui_interface->closeBox();
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0_ptr = inputs[0];
		FAUSTFLOAT* output0_ptr = outputs[0];
		float fSlow0 = (0.0157079641f * float(fHslider0));
		float fSlow1 = (fConst2 * std::cos(fSlow0));
		float fRec0_tmp[36];
		float* fRec0 = &fRec0_tmp[4];
		float fRec6_tmp[36];
		float* fRec6 = &fRec6_tmp[4];
		float fSlow2 = (fConst4 * float(fHslider1));
		float fRec8_tmp[36];
		float* fRec8 = &fRec8_tmp[4];
		int iSlow3 = int(float(fHslider2));
		float fRec7_tmp[36];
		float* fRec7 = &fRec7_tmp[4];
		float fSlow4 = (fConst2 * float(fHslider3));
		float fRec10_tmp[36];
		float* fRec10 = &fRec10_tmp[4];
		float fZec0[32];
		float fRec9_tmp[36];
		float* fRec9 = &fRec9_tmp[4];
		float fSlow5 = (fConst2 * (iSlow3 ? 39.4868202f : 62.3695068f));
		float fRec11_tmp[36];
		float* fRec11 = &fRec11_tmp[4];
		float fSlow6 = (fConst2 * (iSlow3 ? 96.8631363f : 114.232643f));
		float fRec12_tmp[36];
		float* fRec12 = &fRec12_tmp[4];
		float fSlow7 = (fConst2 * float(fHslider4));
		float fRec14_tmp[36];
		float* fRec14 = &fRec14_tmp[4];
		float fZec1[32];
		float fRec13_tmp[36];
		float* fRec13 = &fRec13_tmp[4];
		float fZec2[32];
		float fZec3[32];
		int iZec4[32];
		float fZec5[32];
		float fZec6[32];
		float fRec5_tmp[36];
		float* fRec5 = &fRec5_tmp[4];
		float fRec4_tmp[36];
		float* fRec4 = &fRec4_tmp[4];
		float fRec3_tmp[36];
		float* fRec3 = &fRec3_tmp[4];
		float fRec2_tmp[36];
		float* fRec2 = &fRec2_tmp[4];
		float fRec1_tmp[36];
		float* fRec1 = &fRec1_tmp[4];
		float fSlow8 = (fConst2 * std::sin(fSlow0));
		float fRec16_tmp[36];
		float* fRec16 = &fRec16_tmp[4];
		float fSlow9 = (fConst2 * float((1 - (float(fCheckbox0) > 0.5f))));
		float fRec17_tmp[36];
		float* fRec17 = &fRec17_tmp[4];
		int vindex = 0;
		/* Main loop */
		for (vindex = 0; (vindex <= (count - 32)); vindex = (vindex + 32)) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			int vsize = 32;
			/* Recursive loop 0 */
			/* Pre code */
			for (int j16 = 0; (j16 < 4); j16 = (j16 + 1)) {
				fRec14_tmp[j16] = fRec14_perm[j16];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec14[i] = (fSlow7 + (fConst1 * fRec14[(i - 1)]));
			}
			/* Post code */
			for (int j17 = 0; (j17 < 4); j17 = (j17 + 1)) {
				fRec14_perm[j17] = fRec14_tmp[(vsize + j17)];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j18 = 0; (j18 < 4); j18 = (j18 + 1)) {
				fRec13_tmp[j18] = fRec13_perm[j18];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec1[i] = (fRec13[(i - 1)] + (fConst5 * fRec14[(i - 1)]));
				fRec13[i] = (fZec1[i] - std::floor(fZec1[i]));
			}
			/* Post code */
			for (int j19 = 0; (j19 < 4); j19 = (j19 + 1)) {
				fRec13_perm[j19] = fRec13_tmp[(vsize + j19)];
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec3[i] = (128.0f * fRec13[i]);
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j8 = 0; (j8 < 4); j8 = (j8 + 1)) {
				fRec10_tmp[j8] = fRec10_perm[j8];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec10[i] = (fSlow4 + (fConst1 * fRec10[(i - 1)]));
			}
			/* Post code */
			for (int j9 = 0; (j9 < 4); j9 = (j9 + 1)) {
				fRec10_perm[j9] = fRec10_tmp[(vsize + j9)];
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				iZec4[i] = int(fZec3[i]);
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j4 = 0; (j4 < 4); j4 = (j4 + 1)) {
				fRec8_tmp[j4] = fRec8_perm[j4];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec8[i] = (fSlow2 + (fConst1 * fRec8[(i - 1)]));
			}
			/* Post code */
			for (int j5 = 0; (j5 < 4); j5 = (j5 + 1)) {
				fRec8_perm[j5] = fRec8_tmp[(vsize + j5)];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec0[i] = std::exp((fConst5 * (0.0f - (6.28318548f * fRec10[i]))));
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j12 = 0; (j12 < 4); j12 = (j12 + 1)) {
				fRec11_tmp[j12] = fRec11_perm[j12];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec11[i] = (fSlow5 + (fConst1 * fRec11[(i - 1)]));
			}
			/* Post code */
			for (int j13 = 0; (j13 < 4); j13 = (j13 + 1)) {
				fRec11_perm[j13] = fRec11_tmp[(vsize + j13)];
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j14 = 0; (j14 < 4); j14 = (j14 + 1)) {
				fRec12_tmp[j14] = fRec12_perm[j14];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec12[i] = (fSlow6 + (fConst1 * fRec12[(i - 1)]));
			}
			/* Post code */
			for (int j15 = 0; (j15 < 4); j15 = (j15 + 1)) {
				fRec12_perm[j15] = fRec12_tmp[(vsize + j15)];
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec5[i] = float(iZec4[i]);
			}
			/* Recursive loop 10 */
			/* Pre code */
			for (int j2 = 0; (j2 < 4); j2 = (j2 + 1)) {
				fRec6_tmp[j2] = fRec6_perm[j2];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec6[i] = (float(input0[i]) + (fConst3 * fRec6[(i - 1)]));
			}
			/* Post code */
			for (int j3 = 0; (j3 < 4); j3 = (j3 + 1)) {
				fRec6_perm[j3] = fRec6_tmp[(vsize + j3)];
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j6 = 0; (j6 < 4); j6 = (j6 + 1)) {
				fRec7_tmp[j6] = fRec7_perm[j6];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec7[i] = ((fConst1 * fRec7[(i - 1)]) + (fConst2 * (iSlow3 ? fRec8[i] : (0.100000001f * fRec8[i]))));
			}
			/* Post code */
			for (int j7 = 0; (j7 < 4); j7 = (j7 + 1)) {
				fRec7_perm[j7] = fRec7_tmp[(vsize + j7)];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec2[i] = (fZec0[i] + 1.0f);
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec6[i] = ((fConst8 * std::pow(2.0f, (0.0833333358f * ((fRec11[i] + ((fRec12[i] - fRec11[i]) * ((ftbl0mydspSIG0[iZec4[i]] * (fZec5[i] + (1.0f - fZec3[i]))) + ((fZec3[i] - fZec5[i]) * ftbl0mydspSIG0[((iZec4[i] + 1) % 128)])))) + -69.0f)))) + -1.0f);
			}
			/* Recursive loop 14 */
			/* Pre code */
			for (int j0 = 0; (j0 < 4); j0 = (j0 + 1)) {
				fRec0_tmp[j0] = fRec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec0[i] = (fSlow1 + (fConst1 * fRec0[(i - 1)]));
			}
			/* Post code */
			for (int j1 = 0; (j1 < 4); j1 = (j1 + 1)) {
				fRec0_perm[j1] = fRec0_tmp[(vsize + j1)];
			}
			/* Recursive loop 15 */
			/* Pre code */
			for (int j10 = 0; (j10 < 4); j10 = (j10 + 1)) {
				fRec9_tmp[j10] = fRec9_perm[j10];
			}
			for (int j20 = 0; (j20 < 4); j20 = (j20 + 1)) {
				fRec5_tmp[j20] = fRec5_perm[j20];
			}
			for (int j22 = 0; (j22 < 4); j22 = (j22 + 1)) {
				fRec4_tmp[j22] = fRec4_perm[j22];
			}
			for (int j24 = 0; (j24 < 4); j24 = (j24 + 1)) {
				fRec3_tmp[j24] = fRec3_perm[j24];
			}
			for (int j26 = 0; (j26 < 4); j26 = (j26 + 1)) {
				fRec2_tmp[j26] = fRec2_perm[j26];
			}
			for (int j28 = 0; (j28 < 4); j28 = (j28 + 1)) {
				fRec1_tmp[j28] = fRec1_perm[j28];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec9[i] = (fRec1[(i - 1)] + (fRec9[(i - 1)] * fZec0[i]));
				fRec5[i] = (((fConst7 * fRec6[(i - 1)]) + ((fRec7[i] * ((0.5f * (fRec9[i] * fZec2[i])) + (fRec9[(i - 1)] * (0.0f - (0.5f * fZec2[i]))))) + (fConst6 * fRec6[i]))) - (fRec5[(i - 1)] * fZec6[i]));
				fRec4[i] = (fRec5[(i - 1)] + (fZec6[i] * (fRec5[i] - fRec4[(i - 1)])));
				fRec3[i] = (fRec4[(i - 1)] + (fZec6[i] * (fRec4[i] - fRec3[(i - 1)])));
				fRec2[i] = (fRec3[(i - 1)] + (fZec6[i] * (fRec3[i] - fRec2[(i - 1)])));
				fRec1[i] = (fRec2[(i - 1)] + (fRec2[i] * fZec6[i]));
			}
			/* Post code */
			for (int j11 = 0; (j11 < 4); j11 = (j11 + 1)) {
				fRec9_perm[j11] = fRec9_tmp[(vsize + j11)];
			}
			for (int j21 = 0; (j21 < 4); j21 = (j21 + 1)) {
				fRec5_perm[j21] = fRec5_tmp[(vsize + j21)];
			}
			for (int j23 = 0; (j23 < 4); j23 = (j23 + 1)) {
				fRec4_perm[j23] = fRec4_tmp[(vsize + j23)];
			}
			for (int j25 = 0; (j25 < 4); j25 = (j25 + 1)) {
				fRec3_perm[j25] = fRec3_tmp[(vsize + j25)];
			}
			for (int j27 = 0; (j27 < 4); j27 = (j27 + 1)) {
				fRec2_perm[j27] = fRec2_tmp[(vsize + j27)];
			}
			for (int j29 = 0; (j29 < 4); j29 = (j29 + 1)) {
				fRec1_perm[j29] = fRec1_tmp[(vsize + j29)];
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j30 = 0; (j30 < 4); j30 = (j30 + 1)) {
				fRec16_tmp[j30] = fRec16_perm[j30];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec16[i] = (fSlow8 + (fConst1 * fRec16[(i - 1)]));
			}
			/* Post code */
			for (int j31 = 0; (j31 < 4); j31 = (j31 + 1)) {
				fRec16_perm[j31] = fRec16_tmp[(vsize + j31)];
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j32 = 0; (j32 < 4); j32 = (j32 + 1)) {
				fRec17_tmp[j32] = fRec17_perm[j32];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec17[i] = (fSlow9 + (fConst1 * fRec17[(i - 1)]));
			}
			/* Post code */
			for (int j33 = 0; (j33 < 4); j33 = (j33 + 1)) {
				fRec17_perm[j33] = fRec17_tmp[(vsize + j33)];
			}
			/* Vectorizable loop 18 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fHbargraph0 = FAUSTFLOAT(fRec17[i]);
				output0[i] = FAUSTFLOAT(((((float(input0[i]) * fRec0[i]) + (fRec1[i] * fRec16[i])) * fRec17[i]) + (float(input0[i]) * (1.0f - fRec17[i]))));
			}
		}
		/* Remaining frames */
		if (vindex < count) {
			FAUSTFLOAT* input0 = &input0_ptr[vindex];
			FAUSTFLOAT* output0 = &output0_ptr[vindex];
			int vsize = (count - vindex);
			/* Recursive loop 0 */
			/* Pre code */
			for (int j16 = 0; (j16 < 4); j16 = (j16 + 1)) {
				fRec14_tmp[j16] = fRec14_perm[j16];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec14[i] = (fSlow7 + (fConst1 * fRec14[(i - 1)]));
			}
			/* Post code */
			for (int j17 = 0; (j17 < 4); j17 = (j17 + 1)) {
				fRec14_perm[j17] = fRec14_tmp[(vsize + j17)];
			}
			/* Recursive loop 1 */
			/* Pre code */
			for (int j18 = 0; (j18 < 4); j18 = (j18 + 1)) {
				fRec13_tmp[j18] = fRec13_perm[j18];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec1[i] = (fRec13[(i - 1)] + (fConst5 * fRec14[(i - 1)]));
				fRec13[i] = (fZec1[i] - std::floor(fZec1[i]));
			}
			/* Post code */
			for (int j19 = 0; (j19 < 4); j19 = (j19 + 1)) {
				fRec13_perm[j19] = fRec13_tmp[(vsize + j19)];
			}
			/* Vectorizable loop 2 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec3[i] = (128.0f * fRec13[i]);
			}
			/* Recursive loop 3 */
			/* Pre code */
			for (int j8 = 0; (j8 < 4); j8 = (j8 + 1)) {
				fRec10_tmp[j8] = fRec10_perm[j8];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec10[i] = (fSlow4 + (fConst1 * fRec10[(i - 1)]));
			}
			/* Post code */
			for (int j9 = 0; (j9 < 4); j9 = (j9 + 1)) {
				fRec10_perm[j9] = fRec10_tmp[(vsize + j9)];
			}
			/* Vectorizable loop 4 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				iZec4[i] = int(fZec3[i]);
			}
			/* Recursive loop 5 */
			/* Pre code */
			for (int j4 = 0; (j4 < 4); j4 = (j4 + 1)) {
				fRec8_tmp[j4] = fRec8_perm[j4];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec8[i] = (fSlow2 + (fConst1 * fRec8[(i - 1)]));
			}
			/* Post code */
			for (int j5 = 0; (j5 < 4); j5 = (j5 + 1)) {
				fRec8_perm[j5] = fRec8_tmp[(vsize + j5)];
			}
			/* Vectorizable loop 6 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec0[i] = std::exp((fConst5 * (0.0f - (6.28318548f * fRec10[i]))));
			}
			/* Recursive loop 7 */
			/* Pre code */
			for (int j12 = 0; (j12 < 4); j12 = (j12 + 1)) {
				fRec11_tmp[j12] = fRec11_perm[j12];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec11[i] = (fSlow5 + (fConst1 * fRec11[(i - 1)]));
			}
			/* Post code */
			for (int j13 = 0; (j13 < 4); j13 = (j13 + 1)) {
				fRec11_perm[j13] = fRec11_tmp[(vsize + j13)];
			}
			/* Recursive loop 8 */
			/* Pre code */
			for (int j14 = 0; (j14 < 4); j14 = (j14 + 1)) {
				fRec12_tmp[j14] = fRec12_perm[j14];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec12[i] = (fSlow6 + (fConst1 * fRec12[(i - 1)]));
			}
			/* Post code */
			for (int j15 = 0; (j15 < 4); j15 = (j15 + 1)) {
				fRec12_perm[j15] = fRec12_tmp[(vsize + j15)];
			}
			/* Vectorizable loop 9 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec5[i] = float(iZec4[i]);
			}
			/* Recursive loop 10 */
			/* Pre code */
			for (int j2 = 0; (j2 < 4); j2 = (j2 + 1)) {
				fRec6_tmp[j2] = fRec6_perm[j2];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec6[i] = (float(input0[i]) + (fConst3 * fRec6[(i - 1)]));
			}
			/* Post code */
			for (int j3 = 0; (j3 < 4); j3 = (j3 + 1)) {
				fRec6_perm[j3] = fRec6_tmp[(vsize + j3)];
			}
			/* Recursive loop 11 */
			/* Pre code */
			for (int j6 = 0; (j6 < 4); j6 = (j6 + 1)) {
				fRec7_tmp[j6] = fRec7_perm[j6];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec7[i] = ((fConst1 * fRec7[(i - 1)]) + (fConst2 * (iSlow3 ? fRec8[i] : (0.100000001f * fRec8[i]))));
			}
			/* Post code */
			for (int j7 = 0; (j7 < 4); j7 = (j7 + 1)) {
				fRec7_perm[j7] = fRec7_tmp[(vsize + j7)];
			}
			/* Vectorizable loop 12 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec2[i] = (fZec0[i] + 1.0f);
			}
			/* Vectorizable loop 13 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fZec6[i] = ((fConst8 * std::pow(2.0f, (0.0833333358f * ((fRec11[i] + ((fRec12[i] - fRec11[i]) * ((ftbl0mydspSIG0[iZec4[i]] * (fZec5[i] + (1.0f - fZec3[i]))) + ((fZec3[i] - fZec5[i]) * ftbl0mydspSIG0[((iZec4[i] + 1) % 128)])))) + -69.0f)))) + -1.0f);
			}
			/* Recursive loop 14 */
			/* Pre code */
			for (int j0 = 0; (j0 < 4); j0 = (j0 + 1)) {
				fRec0_tmp[j0] = fRec0_perm[j0];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec0[i] = (fSlow1 + (fConst1 * fRec0[(i - 1)]));
			}
			/* Post code */
			for (int j1 = 0; (j1 < 4); j1 = (j1 + 1)) {
				fRec0_perm[j1] = fRec0_tmp[(vsize + j1)];
			}
			/* Recursive loop 15 */
			/* Pre code */
			for (int j10 = 0; (j10 < 4); j10 = (j10 + 1)) {
				fRec9_tmp[j10] = fRec9_perm[j10];
			}
			for (int j20 = 0; (j20 < 4); j20 = (j20 + 1)) {
				fRec5_tmp[j20] = fRec5_perm[j20];
			}
			for (int j22 = 0; (j22 < 4); j22 = (j22 + 1)) {
				fRec4_tmp[j22] = fRec4_perm[j22];
			}
			for (int j24 = 0; (j24 < 4); j24 = (j24 + 1)) {
				fRec3_tmp[j24] = fRec3_perm[j24];
			}
			for (int j26 = 0; (j26 < 4); j26 = (j26 + 1)) {
				fRec2_tmp[j26] = fRec2_perm[j26];
			}
			for (int j28 = 0; (j28 < 4); j28 = (j28 + 1)) {
				fRec1_tmp[j28] = fRec1_perm[j28];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec9[i] = (fRec1[(i - 1)] + (fRec9[(i - 1)] * fZec0[i]));
				fRec5[i] = (((fConst7 * fRec6[(i - 1)]) + ((fRec7[i] * ((0.5f * (fRec9[i] * fZec2[i])) + (fRec9[(i - 1)] * (0.0f - (0.5f * fZec2[i]))))) + (fConst6 * fRec6[i]))) - (fRec5[(i - 1)] * fZec6[i]));
				fRec4[i] = (fRec5[(i - 1)] + (fZec6[i] * (fRec5[i] - fRec4[(i - 1)])));
				fRec3[i] = (fRec4[(i - 1)] + (fZec6[i] * (fRec4[i] - fRec3[(i - 1)])));
				fRec2[i] = (fRec3[(i - 1)] + (fZec6[i] * (fRec3[i] - fRec2[(i - 1)])));
				fRec1[i] = (fRec2[(i - 1)] + (fRec2[i] * fZec6[i]));
			}
			/* Post code */
			for (int j11 = 0; (j11 < 4); j11 = (j11 + 1)) {
				fRec9_perm[j11] = fRec9_tmp[(vsize + j11)];
			}
			for (int j21 = 0; (j21 < 4); j21 = (j21 + 1)) {
				fRec5_perm[j21] = fRec5_tmp[(vsize + j21)];
			}
			for (int j23 = 0; (j23 < 4); j23 = (j23 + 1)) {
				fRec4_perm[j23] = fRec4_tmp[(vsize + j23)];
			}
			for (int j25 = 0; (j25 < 4); j25 = (j25 + 1)) {
				fRec3_perm[j25] = fRec3_tmp[(vsize + j25)];
			}
			for (int j27 = 0; (j27 < 4); j27 = (j27 + 1)) {
				fRec2_perm[j27] = fRec2_tmp[(vsize + j27)];
			}
			for (int j29 = 0; (j29 < 4); j29 = (j29 + 1)) {
				fRec1_perm[j29] = fRec1_tmp[(vsize + j29)];
			}
			/* Recursive loop 16 */
			/* Pre code */
			for (int j30 = 0; (j30 < 4); j30 = (j30 + 1)) {
				fRec16_tmp[j30] = fRec16_perm[j30];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec16[i] = (fSlow8 + (fConst1 * fRec16[(i - 1)]));
			}
			/* Post code */
			for (int j31 = 0; (j31 < 4); j31 = (j31 + 1)) {
				fRec16_perm[j31] = fRec16_tmp[(vsize + j31)];
			}
			/* Recursive loop 17 */
			/* Pre code */
			for (int j32 = 0; (j32 < 4); j32 = (j32 + 1)) {
				fRec17_tmp[j32] = fRec17_perm[j32];
			}
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fRec17[i] = (fSlow9 + (fConst1 * fRec17[(i - 1)]));
			}
			/* Post code */
			for (int j33 = 0; (j33 < 4); j33 = (j33 + 1)) {
				fRec17_perm[j33] = fRec17_tmp[(vsize + j33)];
			}
			/* Vectorizable loop 18 */
			/* Compute code */
			for (int i = 0; (i < vsize); i = (i + 1)) {
				fHbargraph0 = FAUSTFLOAT(fRec17[i]);
				output0[i] = FAUSTFLOAT(((((float(input0[i]) * fRec0[i]) + (fRec1[i] * fRec16[i])) * fRec17[i]) + (float(input0[i]) * (1.0f - fRec17[i]))));
			}
		}
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




StonePhaserDsp::StonePhaserDsp()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

StonePhaserDsp::~StonePhaserDsp()
{
}

void StonePhaserDsp::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void StonePhaserDsp::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void StonePhaserDsp::process(
    const float *in0,
    float *out0,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),
    };
    float *outputs[] = {
        out0,
    };
    dsp.compute(count, inputs, outputs);

}

const char *StonePhaserDsp::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Bypass";
    
    case 1:
        return "Color";
    
    case 2:
        return "LFO frequency";
    
    case 3:
        return "Feedback depth";
    
    case 4:
        return "Feedback bass cut";
    
    case 5:
        return "Dry/wet mix";
    
    case 6:
        return "Bypass meter";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "Fb bass cut";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "bypass";
    
    case 1:
        return "color";
    
    case 2:
        return "lfo_frequency";
    
    case 3:
        return "feedback_depth";
    
    case 4:
        return "feedback_hpf_cutoff";
    
    case 5:
        return "mix";
    
    case 6:
        return "bypass_meter";
    
    default:
        return 0;
    }
}

const char *StonePhaserDsp::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "Hz";
    
    case 3:
        return "%";
    
    case 4:
        return "Hz";
    
    case 5:
        return "%";
    
    case 6:
        return "";
    
    default:
        return 0;
    }
}

const StonePhaserDsp::ParameterRange *StonePhaserDsp::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 0.2, 0.0099999998, 5 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { 75, 0, 99 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 500, 10, 5000 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 50, 0, 100 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool StonePhaserDsp::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    case 1:
        return true;
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return true;
    
    case 1:
        return true;
    
    case 3:
        return true;
    
    case 5:
        return true;
    
    default:
        return false;
    }
}

bool StonePhaserDsp::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    case 2:
        return true;
    
    case 4:
        return true;
    
    default:
        return false;
    }
}

float StonePhaserDsp::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fCheckbox0;
    
    case 1:
        return dsp.fHslider2;
    
    case 2:
        return dsp.fHslider4;
    
    case 3:
        return dsp.fHslider1;
    
    case 4:
        return dsp.fHslider3;
    
    case 5:
        return dsp.fHslider0;
    
    case 6:
        return dsp.fHbargraph0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void StonePhaserDsp::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fCheckbox0 = value;
        break;
    
    case 1:
        dsp.fHslider2 = value;
        break;
    
    case 2:
        dsp.fHslider4 = value;
        break;
    
    case 3:
        dsp.fHslider1 = value;
        break;
    
    case 4:
        dsp.fHslider3 = value;
        break;
    
    case 5:
        dsp.fHslider0 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float StonePhaserDsp::get_bypass() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fCheckbox0;
}

float StonePhaserDsp::get_color() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float StonePhaserDsp::get_lfo_frequency() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float StonePhaserDsp::get_feedback_depth() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float StonePhaserDsp::get_feedback_hpf_cutoff() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float StonePhaserDsp::get_mix() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float StonePhaserDsp::get_bypass_meter() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHbargraph0;
}


void StonePhaserDsp::set_bypass(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fCheckbox0 = value;
}

void StonePhaserDsp::set_color(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void StonePhaserDsp::set_lfo_frequency(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void StonePhaserDsp::set_feedback_depth(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void StonePhaserDsp::set_feedback_hpf_cutoff(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void StonePhaserDsp::set_mix(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}




