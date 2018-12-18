@FOR /F "tokens=*" %%P IN ('dir /s /b app\*') DO @FOR /F "tokens=*" %%R IN ('dir /s /b %%P.gpj') DO SET PROJ_FILE=%%R
@echo [version] > %temp%\short.inf
@echo signature="$chicago$" >> %temp%\short.inf
@echo [Shortcuts]  >> %temp%\short.inf
@echo UpdateInis=Addlink  >> %temp%\short.inf
@echo [Addlink] >> %temp%\short.inf
@echo setup.ini, progman.groups,, "group1="%temp%"" >> %temp%\short.inf
@echo setup.ini, group1,,""start_multi","""""%PROJ_FILE%"""""" >> %temp%\short.inf
@start/w rundll32 setupapi,InstallHinfSection Shortcuts 128 %temp%\short.inf
@copy %temp%\start_multi.lnk .
@del %temp%\short.inf
@del %temp%\start_multi.lnk
