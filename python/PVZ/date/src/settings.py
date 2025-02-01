from date.src.const import *

# 定义一个字典，用于存储游戏中各种元素的属性
settings = {
                # 植物名称
                'plant_name': ['', 'sunflower', 'peashooter', 'nut', 'potato_mine'],
                # 植物卡片图片路径
                'plant_card_path': ['', 'date/image/PlantCard/Sunflower.png', 'date/image/PlantCard/Peashooter.png', 'date/image/PlantCard/Nut.png', 'date/image/PlantCard/PotatoMine.png'],
                # 游戏设置
                'game': {
                    'bgm':{
                        'startMusic': 'date/bgm/Crazy Dave.mp3',
                        'startMusicVolume': 0.4,
                        'gameMusic': 'date/bgm/Grasswalk.mp3',
                        'gameMusicVolume': 0.4,
                        'sunlight': 'date/bgm/Sun.mp3',
                        'sunVolume': 0.9,
                        'plant': 'date/bgm/Plant.mp3',
                        'plantVolume': 0.1,
                        'zombieEat': 'date/bgm/ZombieEat.mp3',
                        'zombieEatVolume': 0.1,
                        'potatoMineExplode': 'date/bgm/PotatoMineExplode.mp3',
                        'potatoMineExplodeVolume': 0.4,
                        'gameover': 'date/bgm/gameover.mp3',
                        'win': 'date/bgm/win.mp3',
                    },
                    'gridPlantPos':{
                        'sunflower': (10, 0),
                        'peashooter': (10, 0),
                        'nut': (10, 0),
                        'potato_mine': (8, 10),
                    },
                    'plantPreIndexTimeNumber':{
                        'sunflower': 0.1,
                        'peashooter': 0.1,
                        'nut': 0.1,
                        'potato_mine': 0.2,
                    }
                },
                # 阴影
                'shadow':{
                    'name': 'shadow',
                    'path': 'date/image/Other/shadow.png'
                },
                # 卡片选择框
                'ChooseCardFrame':{
                    'name': 'ChooseCardFrame',
                    'size': (470, 500),
                    'path': 'date/image/Other/ChooseCardFrame.png',
                    'pos': (90, 90),
                },
                # 定义豌豆射手
                'peashooter': {
                    'name': 'peashooter',  # 名称
                    'gold': 100,
                    'size': (60, 80),  # 大小
                    'path': 'date/image/Plant/Peashooter/Idle%d.png',  # 图片路径
                    'imageCount': 10,  # 图片数量
                    'shoot_path': 'date/image/Plant/Peashooter/Shoot%d.png',  # 射击图片路径
                    'shoot_imageCount': 8,  # 射击图片数量
                },
                # 定义向日葵
                'sunflower': {
                    'name': 'sunflower',
                    'gold': 50,
                    'size': (60, 80),
                    'path': 'date/image/Plant/Sunflower/Idle%d.png',
                    'imageCount': 12,
                    'shoot_path': 'date/image/Plant/Sunflower/Shoot%d.png',
                    'shoot_imageCount': 15,
                },
                # 定义坚果
                'nut': {
                    'name': 'nut',
                    'path': 'date/image/Plant/Nut/Nut-1 (%d).png',
                    'imageCount': 15,
                    'path1': 'date/image/Plant/Nut/Nut-1 (%d).png',
                    'imageCount1': 15,
                    'path2': 'date/image/Plant/Nut/Nut-2 (%d).png',
                    'imageCount2': 11,
                    'path3': 'date/image/Plant/Nut/Nut-3 (%d).png',
                    'imageCount3': 15,
                    'gold': 50,
                    'size': (60, 70)
                },
                # 定义土豆地雷
                'potato_mine': {
                    'name': 'potato_mine',
                    'gold': 25,
                    'size': (60, 60),
                    'growTime': 600,
                    'explodeTime': 20,
                    'initPath': 'date/image/Plant/PotatoMine/PotatoMineInit.png',
                    'initImageCount': 1,
                    'path': 'date/image/Plant/PotatoMine/PotatoMine (%d).png',
                    'imageCount': 8,
                    'explodePath': 'date/image/Plant/PotatoMine/PotatoMineExplode.png',
                    'explodeImageCount': 1,
                    'explodeSound': 'date/bgm/Explode.mp3',
                },
                # 定义僵尸
                'zombie': {
                    'name': 'zombie',
                    'hp': 100,
                    'size': (110, 110),
                    'path': 'date/image/Zombie/Zombie/Idle (%d).png',
                    'imageCount': 18,
                    'eatPath': 'date/image/Zombie/Zombie/Eat (%d).png',
                    'eatImageCount': 21,
                    'headlessPath': 'date/image/Zombie/Zombie/Headless (%d).png',
                    'headlessImageCount': 18,
                    'deadPath': 'date/image/Zombie/Zombie/die (%d).png',
                    'deadImageCount': 10,
                },
                # 定义僵尸头部
                'zombie_headless': {
                    'path': 'date/image/Zombie/Zombie-turn-around/(%d).png',
                    'imageCount': 12,
                    'size': (110, 110),
                },
                # 定义阳光
                'sunlight': {
                    'name': 'sun',
                    'path': 'date/image/Other/Sunlight/(%d).png',
                    'size': (60, 60),
                    'imageCount': 30,
                },
                # 定义卡片框
                'cardframe': {
                    'name': 'cardframe',
                    'path': 'date/image/Other/CardFrame.png',
                    'size': (540, 90),
                    'pos': (20, 0),
                },
                # 定义背景
                'background': {
                    'name': 'background',
                    'path': 'date/image/Other/background.png',
                    'pos': (0, -130),
                    'size': (1300, 800),
                },
                # 定义开始背景
                'startBackground': {
                    'name': 'startBackground',
                    'path': 'date/image/Other/Start-Background.png',
                    'size': (1200, 700),
                    'pos': (0, -50),
                },
                # 定义豌豆
                'pea': {
                    'name': 'pea',
                    'path': 'date/image/Other/Pea.png',
                    'size': (20, 20),
                },
                # 定义铲子
                'shovel': {
                    'name': 'shovel',
                    'path': 'date/image/Other/Shovel.png',
                    'size': (60, 70),
                },
                # 定义铲子框
                'shovelFrame': {
                    'name': 'shovelFrame',
                    'path': 'date/image/Other/ShovelFrame.png',
                    'pos': (560, 0),
                    'size': (70, 70),
                },
                # 定义游戏结束
                'gameover': {
                    'name': 'gameover',
                    'path': 'date/image/GameOver.png',
                    'size': (1200, 800),
                },
                # 定义开始按钮
                'startButton': {
                    'name': 'startButton',
                    'path': 'date/image/Other/Adventure_1.png',
                    'onPath': 'date/image/Other/Adventure_0.png',
                    'size': (350, 180),
                    'pos': (670, 50),
                },
                # 定义开始按钮
                'reallyButton': {
                    'name': 'startButton',
                    'path': 'date/image/Other/ReallyButton.png',
                    'size': (155, 35),
                    'pos': (247, 540),
                },
           }  