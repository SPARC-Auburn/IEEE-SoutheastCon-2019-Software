from PIL import Image, ImageDraw
import math
#uses pil and some parameters to auto generate the texture for the base of the arena
#this image still needs to be manually copy and pasted into the greater uv map from blender
pixelDim = 4096
arenaDim = 2.44

#dimensions in meters

ratio = pixelDim/arenaDim
arenaDim = round(ratio*arenaDim)
baseDim = round(ratio*.3)
baseTapeWidth = round(ratio*0.0478)

circleRadius = round(ratio*1)
circleTapeWidth = round(ratio*2.54/100)

seperatorColors = [(255,0,0),(255,255,0),(0,0,255),(0,255,0)]
seperatorWidth = baseTapeWidth

img = Image.new("RGB",(pixelDim,pixelDim))

ImageDraw.floodfill(img,(0,0),(0,0,0))
draw = ImageDraw.Draw(img)

#home bases
def drawProperBase(corner,width,xDir,yDir):
    wx = round(xDir*width/2)
    wy = round(yDir*width/2)
    draw.line([(corner[0]+wx+xDir*baseDim,corner[1]),(corner[0]+xDir*baseDim+wx,corner[1]+yDir*baseDim+2*wy)],fill=(255,255,255),width=width)
    draw.line([(corner[0],corner[1]+wy+yDir*baseDim),(corner[0]+xDir*baseDim+2*wx,corner[1]+yDir*baseDim+wy)],fill=(255,255,255),width=width)
    
drawProperBase((0,0),baseTapeWidth,1,1)
drawProperBase((0,pixelDim-1),baseTapeWidth,1,-1)
drawProperBase((pixelDim-1,0),baseTapeWidth,-1,1)
drawProperBase((pixelDim-1,pixelDim-1),baseTapeWidth,-1,-1)

outerRadius = round(circleRadius+circleTapeWidth/2)
innerRadius = round(circleRadius-circleTapeWidth/2)
draw.arc([(pixelDim/2-outerRadius,pixelDim/2-outerRadius),(pixelDim/2+outerRadius,pixelDim/2+outerRadius)],0,360,fill=(255,255,255))
draw.arc([(pixelDim/2-innerRadius,pixelDim/2-innerRadius),(pixelDim/2+innerRadius,pixelDim/2+innerRadius)],0,360,fill=(255,255,255))
ImageDraw.floodfill(img,(round(pixelDim/2+(outerRadius+innerRadius)/2),pixelDim/2),(255,255,255))

dist = abs(round(innerRadius*math.sin(math.acos(seperatorWidth/innerRadius))))
#top
draw.line([(round(pixelDim/2+seperatorWidth/2),pixelDim/2),(round(pixelDim/2+seperatorWidth/2),pixelDim/2-dist)],fill=(255,255,255),width=seperatorWidth)
draw.line([(round(pixelDim/2-seperatorWidth/2),pixelDim/2),(round(pixelDim/2-seperatorWidth/2),pixelDim/2-dist)],fill=seperatorColors[0],width=seperatorWidth)

#left
draw.line([(pixelDim/2,round(pixelDim/2-seperatorWidth/2)),(pixelDim/2-dist,round(pixelDim/2-seperatorWidth/2))],fill=(255,255,255),width=seperatorWidth)
draw.line([(pixelDim/2,round(pixelDim/2+seperatorWidth/2)),(pixelDim/2-dist,round(pixelDim/2+seperatorWidth/2))],fill=seperatorColors[1],width=seperatorWidth)

#bottom
draw.line([(round(pixelDim/2-seperatorWidth/2),pixelDim/2),(round(pixelDim/2-seperatorWidth/2),pixelDim/2+dist)],fill=(255,255,255),width=seperatorWidth)
draw.line([(round(pixelDim/2+seperatorWidth/2),pixelDim/2),(round(pixelDim/2+seperatorWidth/2),pixelDim/2+dist)],fill=seperatorColors[2],width=seperatorWidth)

#right
draw.line([(pixelDim/2,round(pixelDim/2+seperatorWidth/2)),(pixelDim/2+dist,round(pixelDim/2+seperatorWidth/2))],fill=(255,255,255),width=seperatorWidth)
draw.line([(pixelDim/2,round(pixelDim/2-seperatorWidth/2)),(pixelDim/2+dist,round(pixelDim/2-seperatorWidth/2))],fill=seperatorColors[3],width=seperatorWidth)



img.save("test.png", "png")






