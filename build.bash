262  ./extras/pack.release.bash
263  ./extras/pack.betabuild.bash
264  mkdir Realease
265  mkdir BetaRealease
266  mv *beta*.bz2 BetaRealease/
267  mv *beta*.json BetaRealease/
269  mv *.json Realease/
270  mv *.bz2 Realease/