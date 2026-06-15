$psi = New-Object System.Diagnostics.ProcessStartInfo
$psi.FileName = (Resolve-Path "./output/E.exe").Path
$psi.RedirectStandardInput = $true
$psi.RedirectStandardOutput = $true
$psi.UseShellExecute = $false
$psi.WorkingDirectory = (Resolve-Path "./output").Path

$proc = New-Object System.Diagnostics.Process
$proc.StartInfo = $psi

$sw = [System.Diagnostics.Stopwatch]::StartNew()
$proc.Start() | Out-Null

# Write input
$input = Get-Content "./output/E_test.in" -Raw
$proc.StandardInput.Write($input)
$proc.StandardInput.Close()

$maxWS = 0
$maxVM = 0

while (-not $proc.HasExited) {
    try {
        $maxWS = [Math]::Max($maxWS, $proc.WorkingSet64)
        $maxVM = [Math]::Max($maxVM, $proc.VirtualMemorySize64)
    } catch {}
    Start-Sleep -Milliseconds 100
}

$proc.WaitForExit()
$sw.Stop()

# Final check
try {
    $maxWS = [Math]::Max($maxWS, $proc.WorkingSet64)
    $maxVM = [Math]::Max($maxVM, $proc.VirtualMemorySize64)
} catch {}

Write-Host "Exit code:" $proc.ExitCode
Write-Host "Peak WorkingSet (MB):" ([math]::Round($maxWS / 1MB, 2))
Write-Host "Peak VM (MB):" ([math]::Round($maxVM / 1MB, 2))
Write-Host "Elapsed (s):" $sw.Elapsed.TotalSeconds
