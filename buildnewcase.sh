#! /bin/bash
if [[ ${SLURM_JOB_PARTITION} == *"hdr"* ]]; then
  module load gcc netcdf openmpi cmake
elif [[ ${SLURM_JOB_PARTITION} == *"fdr"* || ${SLURM_JOB_PARTITION} == *"edr"* ]]; then
  module load gcc netcdf openmpi cmake
fi
module load gcc netcdf openmpi cmake

export CASENAME=$1
export NCPUS=$2
export TODO=$3
export OUTPUT=/net/fs06/d0/${USER}/athena/data_${CASENAME}
export MyExp=`pwd`

# compile and make
if [[ -z "$TODO" || $TODO == *"compile"*  ]]; then
  mkdir $CASENAME
  cd $CASENAME
  cmake .. -DTASK=$CASENAME
  make -j8
  ln -s ${MyExp}/newrundir .
  ln -s ${MyExp}/tools/*.py* .
  ln -s ${MyExp}/tools/*.sh* .

# construct output folder
  mkdir -p ${OUTPUT}
  ln -sf `pwd`/bin/${CASENAME}.release ${OUTPUT}
  inputfile=`realpath bin/${CASENAME}.inp`
  ln -sf $inputfile ${OUTPUT}
  ln -sf ${MyExp}/tools/*.sh* ${OUTPUT} 
  ln -sf ${MyExp}/tools/*.py* ${OUTPUT} 
  ln -sf ${OUTPUT} .

# compile run.sub
  cp ${MyExp}/run.sub_template $OUTPUT/run.sub
  sed -i "s/_CASENAME_/${CASENAME}/g" $OUTPUT/run.sub
  sed -i "s/_NCPUS_/${NCPUS}/g" $OUTPUT/run.sub
  if [[ ${SLURM_JOB_PARTITION} == *"hdr"* ]]; then
    sed -i "s/_QUEUE_/hdr/g" $OUTPUT/run.sub
  elif [[ ${SLURM_JOB_PARTITION} == *"fdr"* || ${SLURM_JOB_PARTITION} == *"edr"* ]]; then
    sed -i "s/_QUEUE_/edr,fdr/g" $OUTPUT/run.sub
  fi

#cp ${MyExp}/cleandata $OUTPUT/
#chmod +x $OUTPUT/cleandata
#cp ${MyExp}/deleterun $OUTPUT/
#chmod +x $OUTPUT/deleterun

#cp ${MyExp}/jupyter_template.ipynb ${MyExp}/${CASENAME}/
fi

if [[ $TODO == *"clean"* ]]; then
  rm -rf ${OUTPUT}
  rm -rf $CASENAME
fi
