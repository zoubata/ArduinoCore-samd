rm -rf Release
rm -rf BetaRelease

./extras/pack.release.bash
echo ./extras/pack.betabuild.bash 1
mkdir  --parents Release
mkdir  --parents BetaRelease
echo mv *beta*.bz2 BetaRelease/
echo mv *beta*.json BetaRelease/
mv *.json Release/
mv *.bz2 Release/

