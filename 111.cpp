import streamlit as st

# 设置页面配置
st.set_page_config(
    page_title="菜单页面",
    layout="wide",
    initial_sidebar_state="expanded",
)

# 自定义样式（可选）
st.markdown(
    """
    <style>
    /* 隐藏默认的Streamlit菜单和页脚 */
    #MainMenu {visibility: hidden;}
    footer {visibility: hidden;}
    </style>
    """,
    unsafe_allow_html=True
)

# 定义菜单项
menu = ["主页", "数据分析", "可视化", "关于"]
menu_icons = ["🏠", "📊", "📈", "ℹ️"]

# 创建左侧菜单栏
with st.sidebar:
    st.title("导航菜单")
    selection = st.radio(
        "选择一个页面：",
        options=menu,
        index=0,
        format_func=lambda x: x,
    )
    st.sidebar.markdown("---")
    st.sidebar.write("© 2024 你的公司名")

# 根据选择显示内容
if selection == "主页":
    st.header("欢迎来到主页")
    st.write("""
        这里是主页的内容，可以添加介绍或欢迎信息。
    """)
    st.image("https://via.placeholder.com/700x400", use_column_width=True)

elif selection == "数据分析":
    st.header("数据分析")
    st.write("""
        在这里你可以添加数据分析相关的内容，比如数据上传、处理和展示。
    """)
    # 示例：文件上传
    uploaded_file = st.file_uploader("上传一个CSV文件", type=["csv"])
    if uploaded_file is not None:
        import pandas as pd

        df = pd.read_csv(uploaded_file)
        st.write("数据预览：")
        st.dataframe(df.head())
        st.write("数据描述：")
        st.write(df.describe())

elif selection == "可视化":
    st.header("数据可视化")
    st.write("""
        在这里你可以添加数据可视化的内容，比如绘制图表。
    """)
    # 示例：绘制随机数据的折线图
    import numpy as np
    import pandas as pd
    import altair as alt

    data = pd.DataFrame({
        'x': np.arange(100),
        'y': np.random.randn(100).cumsum()
    })

    chart = alt.Chart(data).mark_line().encode(
        x='x',
        y='y'
    ).properties(
        width=700,
        height=400
    )

    st.altair_chart(chart, use_container_width=True)

elif selection == "关于":
    st.header("关于")
    st.write("""
        这是一个使用Streamlit构建的示例应用，展示了如何创建一个带有左侧菜单栏和右侧主体内容的页面。
    """)
    st.write("开发者：你的名字")
    st.write("联系邮箱：your.email@example.com")

# 底部信息（可选）
st.markdown(
    """
    <hr>
    <div style="text-align: center; color: gray;">
        © 2024 你的公司名
    </div>
    """,
    unsafe_allow_html=True
)

