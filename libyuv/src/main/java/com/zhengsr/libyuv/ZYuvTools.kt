package com.zhengsr.libyuv

/**
 * @author by zhengshaorui 2024/6/25
 * describe：libyuv的工具类
 */
object ZYuvTools {

    init {
        System.loadLibrary("ZYuvTools")
    }

    fun scale(src:ByteArray,srcWidth:Int,srcHeight:Int,dst:ByteArray,dstWidth:Int,dstHeight:Int,mode:Int,srcType: SrcType):Int{
       return when(srcType){
            SrcType.NV12 -> nv21Scale(src,srcWidth,srcHeight,dst,dstWidth,dstHeight,mode)
            else -> -1
        }
    }

    private external fun nv21Scale(src:ByteArray,srcWidth:Int,srcHeight:Int,dst:ByteArray,dstWidth:Int,dstHeight:Int,mode:Int):Int

    enum class FilterMode{
        NONE ,      // Point sample; Fastest.
        LINEAR,    // Filter horizontally only.
        BILINEAR,  // Faster than box, but lower quality scaling down.
        BOX         // Highest quality.nv no box mode
    }
    enum class SrcType{
        ARGB,
        NV12,
        NV21
    }
}