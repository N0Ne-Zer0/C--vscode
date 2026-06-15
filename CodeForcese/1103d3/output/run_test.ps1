$p = Start-Process -FilePath './output/E.exe' -RedirectStandardInput './output/E_test.in' -RedirectStandardOutput './output/E_test.out' -PassThru -NoNewWindow
$p.WaitForExit()
Write-Host "Exit code:" $p.ExitCode
Write-Host "Peak WorkingSet (MB):" ([math]::Round($p.PeakWorkingSet64 / 1MB, 2))
Write-Host "Peak VM (MB):" ([math]::Round($p.PeakVirtualMemorySize64 / 1MB, 2))
