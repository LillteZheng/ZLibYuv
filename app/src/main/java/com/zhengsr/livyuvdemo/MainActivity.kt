package com.zhengsr.livyuvdemo

import android.annotation.SuppressLint
import android.graphics.Bitmap
import android.graphics.BitmapFactory
import android.os.Bundle
import android.view.View
import android.widget.ImageView
import android.widget.TextView
import androidx.activity.ComponentActivity
class MainActivity : ComponentActivity() {
    private lateinit var srcBmp :Bitmap
    private lateinit var destText:TextView
    private lateinit var destImg:ImageView
    @SuppressLint("MissingInflatedId")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.layout_main)
        srcBmp = BitmapFactory.decodeResource(resources, R.mipmap.meinv)
        destText = findViewById(R.id.destTxt)
        destImg = findViewById(R.id.destImg)
    }

    private fun initClick(){
        val clickListener = View.OnClickListener {
            when(it.id){
                R.id.scale -> {
                    val scaleBmp = BitmapUtil.bitmapToRgba(srcBmp)
                }
            }
        }

        findViewById<View>(R.id.scale).setOnClickListener(clickListener)
    }
}

