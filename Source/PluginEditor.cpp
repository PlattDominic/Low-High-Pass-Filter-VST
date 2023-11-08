/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
LowAndHighPassFilterAudioProcessorEditor::LowAndHighPassFilterAudioProcessorEditor (LowAndHighPassFilterAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(cutoffFrequencySlider);
    cutoffFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    cutoffFrequencyAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(vts, "cutoff_frequency", cutoffFrequencySlider));

    addAndMakeVisible(cutoffFrequencyLabel);
    cutoffFrequencyLabel.setText("Cutoff Frequency", juce::dontSendNotification);

    addAndMakeVisible(highpassToggleButton);
    highpassToggleAttachment.reset(new AudioProcessorValueTreeState::ButtonAttachment(vts, "highpass_toggle", highpassToggleButton));

    addAndMakeVisible(highpassToggleButtonLabel);
    highpassToggleButtonLabel.setText("Highpass", juce::dontSendNotification);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
}

LowAndHighPassFilterAudioProcessorEditor::~LowAndHighPassFilterAudioProcessorEditor()
{
}

//==============================================================================
void LowAndHighPassFilterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void LowAndHighPassFilterAudioProcessorEditor::resized()
{
    cutoffFrequencySlider.setBounds({ 15, 35, 100, 300 });
    cutoffFrequencyLabel.setBounds({ cutoffFrequencySlider.getX() + 30, cutoffFrequencySlider.getY() - 30, 200, 50 });

    highpassToggleButton.setBounds({ cutoffFrequencySlider.getX(), cutoffFrequencySlider.getY() + cutoffFrequencySlider.getHeight() + 15, 30, 50 });
    highpassToggleButtonLabel.setBounds(
        { cutoffFrequencySlider.getX() + highpassToggleButton.getWidth() + 15,
        highpassToggleButton.getY(),
        cutoffFrequencySlider.getWidth() - highpassToggleButton.getWidth(),
        highpassToggleButton.getHeight() }
    );
}
