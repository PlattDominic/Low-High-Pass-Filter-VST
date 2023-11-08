/*
  ==============================================================================

    LowAndHighpassFilter.h
    Created: 3 Nov 2023 8:22:39am
    Author:  martinezd

  ==============================================================================
*/

#pragma once

#include <vector>
#include "JuceHeader.h"


class LowAndHighpassFilter
{
public:
    void setHighpassToggle(bool highpass);
    void setCutoffFrequency(float cutoffFrequency);
    void setSampleRate(float sampleRate);

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&);
private:
    bool highpassToggle;
    float cutoffFrequency;
    float sampleRate;
    std::vector<float> dnBuffer;


};