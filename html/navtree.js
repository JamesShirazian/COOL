var NAVTREE =
[
  [ "Object Oriented Library for ARM 7", "index.html", [
    [ "Modules", "modules.html", [
      [ "Analoug to Digital Convertor (ADC)", "group__group5.html", null ],
      [ "Digital to Analoug Convertor (DAC)", "group__group6.html", null ],
      [ "Fast Interrupt", "group__group11.html", null ],
      [ "Interrupt", "group__group10.html", null ],
      [ "Keys", "group__group12.html", null ],
      [ "LCD", "group__group4.html", null ],
      [ "Port(GPIO) - Individual pin of ports", "group__group7.html", null ],
      [ "Real Time Clock", "group__group9.html", null ],
      [ "SerialPort - (UART0, UART1)", "group__group8.html", null ]
    ] ],
    [ "Class List", "annotated.html", [
      [ "__FILE", "struct_____f_i_l_e.html", null ],
      [ "ADC", "class_a_d_c.html", null ],
      [ "AttachedTimer", "class_attached_timer.html", null ],
      [ "Buzzer", "class_buzzer.html", null ],
      [ "DAC", "class_d_a_c.html", null ],
      [ "FastInterrupt", "class_fast_interrupt.html", null ],
      [ "Interrupt", "class_interrupt.html", null ],
      [ "Key", "class_key.html", null ],
      [ "LCD", "class_l_c_d.html", null ],
      [ "PortPin", "class_port_pin.html", null ],
      [ "RealTimeClock", "class_real_time_clock.html", null ],
      [ "RX_Desc", "struct_r_x___desc.html", null ],
      [ "RX_Stat", "struct_r_x___stat.html", null ],
      [ "SDCard", "class_s_d_card.html", null ],
      [ "SerialPort", "class_serial_port.html", null ],
      [ "StopWatch", "class_stop_watch.html", null ],
      [ "Timer", "class_timer.html", null ],
      [ "TX_Desc", "struct_t_x___desc.html", null ],
      [ "TX_Stat", "struct_t_x___stat.html", null ]
    ] ],
    [ "Class Index", "classes.html", null ],
    [ "Class Members", "functions.html", null ],
    [ "File List", "files.html", [
      [ "ADC.h", null, null ],
      [ "AttachedTimer.h", null, null ],
      [ "Buzzer.h", null, null ],
      [ "DAC.h", null, null ],
      [ "FastInterrupt.h", null, null ],
      [ "Interrupt.h", null, null ],
      [ "Key.h", null, null ],
      [ "LCD.h", null, null ],
      [ "LPC23_EMAC.h", null, null ],
      [ "MCI_LPC23xx.h", null, null ],
      [ "PortPin.h", null, null ],
      [ "RealTimeClock.h", null, null ],
      [ "SDCard.h", null, null ],
      [ "SerialPort.h", null, null ],
      [ "StopWatch.h", null, null ],
      [ "target.h", null, null ],
      [ "Timer.h", null, null ],
      [ "type.h", null, null ]
    ] ]
  ] ]
];

function createIndent(o,domNode,node,level)
{
  if (node.parentNode && node.parentNode.parentNode)
  {
    createIndent(o,domNode,node.parentNode,level+1);
  }
  var imgNode = document.createElement("img");
  if (level==0 && node.childrenData)
  {
    node.plus_img = imgNode;
    node.expandToggle = document.createElement("a");
    node.expandToggle.href = "javascript:void(0)";
    node.expandToggle.onclick = function() 
    {
      if (node.expanded) 
      {
        $(node.getChildrenUL()).slideUp("fast");
        if (node.isLast)
        {
          node.plus_img.src = node.relpath+"ftv2plastnode.png";
        }
        else
        {
          node.plus_img.src = node.relpath+"ftv2pnode.png";
        }
        node.expanded = false;
      } 
      else 
      {
        expandNode(o, node, false);
      }
    }
    node.expandToggle.appendChild(imgNode);
    domNode.appendChild(node.expandToggle);
  }
  else
  {
    domNode.appendChild(imgNode);
  }
  if (level==0)
  {
    if (node.isLast)
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2plastnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2lastnode.png";
        domNode.appendChild(imgNode);
      }
    }
    else
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2pnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2node.png";
        domNode.appendChild(imgNode);
      }
    }
  }
  else
  {
    if (node.isLast)
    {
      imgNode.src = node.relpath+"ftv2blank.png";
    }
    else
    {
      imgNode.src = node.relpath+"ftv2vertline.png";
    }
  }
  imgNode.border = "0";
}

function newNode(o, po, text, link, childrenData, lastNode)
{
  var node = new Object();
  node.children = Array();
  node.childrenData = childrenData;
  node.depth = po.depth + 1;
  node.relpath = po.relpath;
  node.isLast = lastNode;

  node.li = document.createElement("li");
  po.getChildrenUL().appendChild(node.li);
  node.parentNode = po;

  node.itemDiv = document.createElement("div");
  node.itemDiv.className = "item";

  node.labelSpan = document.createElement("span");
  node.labelSpan.className = "label";

  createIndent(o,node.itemDiv,node,0);
  node.itemDiv.appendChild(node.labelSpan);
  node.li.appendChild(node.itemDiv);

  var a = document.createElement("a");
  node.labelSpan.appendChild(a);
  node.label = document.createTextNode(text);
  a.appendChild(node.label);
  if (link) 
  {
    a.href = node.relpath+link;
  } 
  else 
  {
    if (childrenData != null) 
    {
      a.className = "nolink";
      a.href = "javascript:void(0)";
      a.onclick = node.expandToggle.onclick;
      node.expanded = false;
    }
  }

  node.childrenUL = null;
  node.getChildrenUL = function() 
  {
    if (!node.childrenUL) 
    {
      node.childrenUL = document.createElement("ul");
      node.childrenUL.className = "children_ul";
      node.childrenUL.style.display = "none";
      node.li.appendChild(node.childrenUL);
    }
    return node.childrenUL;
  };

  return node;
}

function showRoot()
{
  var headerHeight = $("#top").height();
  var footerHeight = $("#nav-path").height();
  var windowHeight = $(window).height() - headerHeight - footerHeight;
  navtree.scrollTo('#selected',0,{offset:-windowHeight/2});
}

function expandNode(o, node, imm)
{
  if (node.childrenData && !node.expanded) 
  {
    if (!node.childrenVisited) 
    {
      getNode(o, node);
    }
    if (imm)
    {
      $(node.getChildrenUL()).show();
    } 
    else 
    {
      $(node.getChildrenUL()).slideDown("fast",showRoot);
    }
    if (node.isLast)
    {
      node.plus_img.src = node.relpath+"ftv2mlastnode.png";
    }
    else
    {
      node.plus_img.src = node.relpath+"ftv2mnode.png";
    }
    node.expanded = true;
  }
}

function getNode(o, po)
{
  po.childrenVisited = true;
  var l = po.childrenData.length-1;
  for (var i in po.childrenData) 
  {
    var nodeData = po.childrenData[i];
    po.children[i] = newNode(o, po, nodeData[0], nodeData[1], nodeData[2],
        i==l);
  }
}

function findNavTreePage(url, data)
{
  var nodes = data;
  var result = null;
  for (var i in nodes) 
  {
    var d = nodes[i];
    if (d[1] == url) 
    {
      return new Array(i);
    }
    else if (d[2] != null) // array of children
    {
      result = findNavTreePage(url, d[2]);
      if (result != null) 
      {
        return (new Array(i).concat(result));
      }
    }
  }
  return null;
}

function initNavTree(toroot,relpath)
{
  var o = new Object();
  o.toroot = toroot;
  o.node = new Object();
  o.node.li = document.getElementById("nav-tree-contents");
  o.node.childrenData = NAVTREE;
  o.node.children = new Array();
  o.node.childrenUL = document.createElement("ul");
  o.node.getChildrenUL = function() { return o.node.childrenUL; };
  o.node.li.appendChild(o.node.childrenUL);
  o.node.depth = 0;
  o.node.relpath = relpath;

  getNode(o, o.node);

  o.breadcrumbs = findNavTreePage(toroot, NAVTREE);
  if (o.breadcrumbs == null)
  {
    o.breadcrumbs = findNavTreePage("index.html",NAVTREE);
  }
  if (o.breadcrumbs != null && o.breadcrumbs.length>0)
  {
    var p = o.node;
    for (var i in o.breadcrumbs) 
    {
      var j = o.breadcrumbs[i];
      p = p.children[j];
      expandNode(o,p,true);
    }
    p.itemDiv.className = p.itemDiv.className + " selected";
    p.itemDiv.id = "selected";
    $(window).load(showRoot);
  }
}

