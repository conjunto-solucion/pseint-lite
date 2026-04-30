
#define MyAppName "PSeIntLite"
#define MyAppVersion "20210609-lite"
#define MyAppPublisher "Pablo Novara"
#define MyAppURL "https://github.com/conjunto-solucion/pseint-lite"
#define MyAppExeName "wxPSeInt.exe"

[Setup]
AppId={{3BD1C406-A23E-410A-85C3-B2FB36BA3DE6}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
;AppPublisher={#MyAppPublisher}
;AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DisableProgramGroupPage=yes
DisableWelcomePage=no
LicenseFile=license.txt
SetupIconFile=pseint/imgs/icon.ico
WizardSmallImageFile=installer-image-small.bmp
WizardImageFile=installer-image-large.bmp
WizardImageAlphaFormat=defined
; Uncomment the following line to run in non administrative install mode (install for current user only.)
;PrivilegesRequired=lowest
PrivilegesRequiredOverridesAllowed=commandline
OutputDir=.
OutputBaseFilename=pseint-lite-installer
DisableReadyPage=yes
DisableDirPage=no
Compression=lzma
SolidCompression=yes
WizardStyle=modern
DirExistsWarning=no
;CreateUninstallRegKey=no
;Uninstallable=no
;UninstallDisplayName=PSeInt

[Languages]
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"

[Messages]
WelcomeLabel2=%n%nEste programa instalará [name/ver] en su computadora.%n

;[Tasks]
;Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: checked

[Files]
Source: "pseint\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "config.here"; DestDir: "{app}"; Permissions: users-modify


[Icons]
;Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
;Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}";
;Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; IconFilename: "{app}\imgs\icon.ico"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; IconFilename: "{app}\imgs\icon.ico"

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

[Code]
procedure CurPageChanged(CurPageID: Integer);
begin
  if CurPageID = wpSelectDir then
    WizardForm.NextButton.Caption := SetupMessage(msgButtonInstall)
  else
    WizardForm.NextButton.Caption := SetupMessage(msgButtonNext);
end;

