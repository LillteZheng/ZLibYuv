package com.zhengsr.livyuvdemo

import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Bundle
import androidx.activity.ComponentActivity
class MainActivity : ComponentActivity() {
    private lateinit var srcBmp :Bitmap
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.layout_main)
        srcBmp = BitmapFactory.decodeResource(resources, R.mipmap.meinv)
    }
}

