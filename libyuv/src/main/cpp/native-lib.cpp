#include <jni.h>
#include <string>
#include "libyuv.h"
#include <android/log.h>

extern "C"
jint
Java_com_example_virtualcamera_YuvTools_getIntValue(JNIEnv *env, jobject thiz, jint a, jint b) {
    return 6;
}


extern "C"
JNIEXPORT int JNICALL
Java_com_zhengsr_libyuv_ZYuvTools_nv21Scale(JNIEnv *env, jobject thiz, jbyteArray src,
                                                  jint src_width, jint src_height, jbyteArray dst,
                                                  jint dst_width, jint dst_height, jint mode) {

    //拿到符合 jni 的类型
    jbyte *srcYuv = env->GetByteArrayElements(src, JNI_FALSE);
    jbyte *destYuv = env->GetByteArrayElements(dst, JNI_FALSE);

    //拿到 y,uv 数据
    const uint8_t *src_y = reinterpret_cast<const uint8_t *>(srcYuv);
    //指针+大小，相当于指针移动，这里移动了 src_width * src_height 个字节，也就是 y 数据的大小，拿到 uv 数据
    const uint8_t *src_uv = src_y + src_width * src_height;

    uint8_t *dst_y = reinterpret_cast<uint8_t *>(destYuv);
    uint8_t *dst_uv = dst_y + dst_width * dst_height;
    /**
     * int NV12Scale(
              const uint8_t* src_y,
              int src_stride_y,
              const uint8_t* src_uv,
              int src_stride_uv,
              int src_width,
              int src_height,
              uint8_t* dst_y,
              int dst_stride_y,
              uint8_t* dst_uv,
              int dst_stride_uv,
              int dst_width,
              int dst_height,
              enum FilterMode filtering);
     */

    int result = libyuv::NV12Scale(
            src_y,
            src_width,
            src_uv,
            src_width,
            src_width,
            src_height,
            dst_y,
            dst_width,
            dst_uv,
            dst_width,
            dst_width,
            dst_height,
            static_cast<libyuv::FilterMode>(mode)
    );

    //__android_log_print(ANDROID_LOG_ERROR, "YuvTools", "result = %d", result);

    env->ReleaseByteArrayElements(src, srcYuv, 0);
    env->ReleaseByteArrayElements(dst, destYuv, 0);

    return result;

}

extern "C"
JNIEXPORT void JNICALL
Java_com_zhengsr_libyuv_ZYuvTools_nv21Scale2(JNIEnv *env, jobject thiz, jobject src,
                                                   jint src_width, jint src_height, jobject dst,
                                                   jint dst_width, jint dst_height, jint mode) {

    //拿到符合 jni 的类型
    uint8_t *src_y =(uint8_t *) env->GetDirectBufferAddress(src);
    uint8_t *dst_y = (uint8_t *) env->GetDirectBufferAddress(dst);

    //拿到 y,uv 数据
    //指针+大小，相当于指针移动，这里移动了 src_width * src_height 个字节，也就是 y 数据的大小，拿到 uv 数据
    const uint8_t *src_uv = src_y + src_width * src_height;

    uint8_t *dst_uv = dst_y + dst_width * dst_height;

    int result = libyuv::NV12Scale(
            src_y,
            src_width,
            src_uv,
            src_width,
            src_width,
            src_height,
            dst_y,
            dst_width,
            dst_uv,
            dst_width,
            dst_width,
            dst_height,
            static_cast<libyuv::FilterMode>(mode)
    );
}