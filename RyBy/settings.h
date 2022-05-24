#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
int overallVolume;
int musicVolume;
int soundVolume;

int brightness;
int saturation;
int contrast;

bool isJoyXAxisInverted;
bool isJoyYAxisInverted;
bool isConXAxisInverted;
bool isConYAxisInverted;


public:
    Settings();

    void update();
};

#endif // SETTINGS_H
