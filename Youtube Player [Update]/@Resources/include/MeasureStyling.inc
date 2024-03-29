[MeasureSetDynamicColors]
Measure=Calc
Formula=#EnableDynamicColors#
IfBelowValue=1
IfBelowAction=[!DisableMeasure MeasureGenre][!DisableMeasure MeasureGetCoverColor][!DisableMeasure MeasureCoverColor]
IfEqualValue=1
IfEqualAction=[!EnableMeasure MeasureGenre][!DisableMeasure MeasureGetCoverColor][!DisableMeasure MeasureCoverColor]
IfAboveValue=1
IfAboveAction=[!DisableMeasure MeasureGenre][!EnableMeasure MeasureGetCoverColor][!EnableMeasure MeasureCoverColor]
UpdateDivider=-1

[MeasureEnableDropShadow]
Measure=Calc
Formula=#EnableDropShadow#
IfBelowValue=1
IfBelowAction=[!HideMeterGroup GroupShadowBars][!HideMeter MeterCoverDropShadow][!SetVariable DropShadowColor "0,0,0,0"]
IfEqualAction=[!ShowMeterGroup GroupShadowBars][!ShowMeter MeterCoverDropShadow][!SetVariable DropShadowColor #*DropShadowColor*#]
IfAboveValue=1
IfAboveAction=[!ShowMeterGroup GroupShadowBars][!ShowMeter MeterCoverDropShadow][!SetVariable DropShadowColor #*DropShadowColor*#]
UpdateDivider=-1

[MeasureSetMediaPlayer]
Measure=String
String=#PlayerName#
IfMatch=Spotify
IfMatchAction=[!WriteKeyValue Variables MPMode Spotify "#@#variables.ini"][!DisableMeasure MeasureGenre]
IfMatch2=GPMDP
IfMatchAction2=[!WriteKeyValue Variables MPMode GPMDP "#@#variables.ini"][!DisableMeasure MeasureGenre]
IfMatch3=Web
IfMatchAction3=[!WriteKeyValue Variables MPMode Web "#@#variables.ini"][!DisableMeasure MeasureGenre]
IfNotMatchAction=[!WriteKeyValue Variables MPMode NowPlaying "#@#variables.ini"]
UpdateDivider=-1

[MeasureInvertVisualizer]
Measure=Calc
Formula=#InvertVisualizer#
IfEqualValue=1
IfEqualAction=[!SetOption ScriptFactoryBars Value3 "MeasureAudioSmoothed{#BarCount# - %% - 1}"][!SetOption ScriptFactoryShadowBars Value3 "MeasureAudioSmoothed{#BarCount# - %% - 1}"][!UpdateMeasure "ScriptFactoryBars"][!CommandMeasure "ScriptFactoryBars" "Initialize()"][!UpdateMeasure "ScriptFactoryShadowBars"][!CommandMeasure "ScriptFactoryShadowBars" "Initialize()"]
IfBelowValue=1
IfBelowAction=[!SetOption ScriptFactoryBars Value3 "MeasureAudioSmoothed{%%}"][!SetOption ScriptFactoryShadowBars Value3 "MeasureAudioSmoothed{%%}"][!UpdateMeasure "ScriptFactoryBars"][!UpdateMeasure "ScriptFactoryShadowBars"][!CommandMeasure "ScriptFactoryBars" "Initialize()"][!CommandMeasure "ScriptFactoryShadowBars" "Initialize()"]
UpdateDivider=-1

[MeasureClipSongInformation]
Measure=Calc
Formula=#ClipSongInformation#
IfEqualValue=1
IfEqualAction=[!SetOption MeterArtist W "#SkinWidth#"][!SetOption MeterTrack W "#SkinWidth#"]
IfBelowValue=1
IfBelowAction=[!SetOption MeterArtist ClipString 2]
UpdateDivider=-1

[MeasureAddTextBorder]
Measure=Calc
Formula=#AddTextBorder#
IfEqualValue=1
IfEqualAction=[!SetOption MeterArtist StringEffect "Border"][!SetOption MeterTrack StringEffect "Border"]
UpdateDivider=-1

[MeasureStaticColor]
Measure=String
String=#Color#
UpdateDivider=-1

[MeasureStaticColorText]
Measure=String
String=#TextColor#
UpdateDivider=-1

[MeasureGenre]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#PlayerName#
PlayerType=Genre
; You can add your own genres here.
; Use | as dividier and replace spaces with \s (otherwise it won't work)
; Electro
IfMatch=Electro
IfMatchAction=[!SetVariable GenreColor "#Electro#"]
; Electronic/EDM
IfMatch2=EDM|Electronic|Breaks|Chillout|Bounce|Chill
IfMatchAction2=[!SetVariable GenreColor "#EDM#"]
; House/Progressive House
IfMatch3=House|Electro\sHouse|Progressive\sHouse
IfMatchAction3=[!SetVariable GenreColor "#House#"]
; Drum & Bass
IfMatch4=Drum\s&\sBass|DnB
IfMatchAction4=[!SetVariable GenreColor "#DnB#"]
; Dubstep
IfMatch5=Dubstep
IfMatchAction5=[!SetVariable GenreColor "#Dubstep#"]
; Drumstep
IfMatch6=Drumstep
IfMatchAction6=[!SetVariable GenreColor "#Drumstep#"]
; Glitch Hop
IfMatch7=Glitch\sHop|GlitchHop
IfMatchAction7=[!SetVariable GenreColor "#GlitchHop#"]
; Trap
IfMatch8=Trap
IfMatchAction8=[!SetVariable GenreColor "#Trap#"]
; Trance
IfMatch9=Trance|Deep\sHouse
IfMatchAction9=[!SetVariable GenreColor "#Trance#"]
; Hard Dance
IfMatch10=Hard\sDance
IfMatchAction10=[!SetVariable GenreColor "#HardDance#"]
; Nu Disco/Indie Dance
IfMatch11=Nu\sDisco|NuDisco|Disco|Indie\sDance|Electro\sSwing
IfMatchAction11=[!SetVariable GenreColor "#NuDisco#"]
; Future Bass
IfMatch12=Future|Future\sBass
IfMatchAction12=[!SetVariable GenreColor "#FutureBass#"]
; Here is an example for an custom genre. Colors need to be rgb(a) values.
IfMatch13=Mashup|Mash\sUp
IfMatchAction13=[!SetVariable GenreColor "192,255,99"]
Substitute="":"#Color#"
OnChangeAction=[!UpdateMeasure "CalcColors"]
Disabled=1

[CalcColors]
Measure=Calc
IfConditionMode=1
IfCondition= (#EnableDynamicColors# = 0) && (#DisableDynamicFontColors# = 1)
IfTrueAction=[!SetVariable Color "[MeasureStaticColor]"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
IfCondition2= (#EnableDynamicColors# = 1) && (#DisableDynamicFontColors# = 1)
IfTrueAction2=[!SetVariable Color "#GenreColor#"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
IfCondition3= (#EnableDynamicColors# = 2) && (#DisableDynamicFontColors# = 1)
IfTrueAction3=[!SetVariable Color "[MeasureCoverColor]"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
IfCondition4= (#EnableDynamicColors# = 0) && (#DisableDynamicFontColors# = 0)
IfTrueAction4=[!SetVariable Color "[MeasureStaticColor]"][!SetVariable TextColor "[MeasureStaticColor]"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
IfCondition5= (#EnableDynamicColors# = 1) && (#DisableDynamicFontColors# = 0)
IfTrueAction5=[!SetVariable Color "#GenreColor#"][!SetVariable TextColor "#GenreColor#"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
IfCondition6= (#EnableDynamicColors# = 2) && (#DisableDynamicFontColors# = 0)
IfTrueAction6=[!SetVariable Color "[MeasureCoverColor]"][!SetVariable TextColor "[MeasureCoverColor]"][!SetOptionGroup GroupDynamicColors DynamicVariables "0"]
UpdateDivider=-1
DynamicVariables=1
