param(
    [string]$folder = "."
)

# 查找当前目录下的 .cpp 文件（不递归）
$files = Get-ChildItem -Path $folder -Filter "*.cpp" | ForEach-Object { $_.FullName }
if (-not $files) {
    Write-Host "没有在目录 $folder 找到 .cpp 文件。"
    exit 1
}

$exe = Join-Path $folder "program.exe"
Write-Host "Compiling $($files.Count) file(s) to $exe"

& g++ -g $files -o $exe

if ($LASTEXITCODE -ne 0) {
    Write-Host "g++ 返回非零退出码： $LASTEXITCODE"
    exit $LASTEXITCODE
}
Write-Host "构建成功： $exe"