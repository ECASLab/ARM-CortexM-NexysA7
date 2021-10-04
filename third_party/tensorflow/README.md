## Tensorflow Lite Micro target Cortex-M Generic
Projects created by command:

python3 $TFLITE_MICRO_REPO_PATH/tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py \
  -e hello_world -e magic_wand -e micro_speech -e person_detection \
  --makefile_options="TARGET=cortex_m_generic OPTIMIZED_KERNEL_DIR=cmsis_nn TARGET_ARCH=project_generation" \
  $REPO_PATH/third_party/tensorflow/tflite-micro-cmsis

