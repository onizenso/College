<?php /* Smarty version Smarty-3.1.8, created on 2013-10-31 12:47:00
         compiled from "/home/stu/nramsey/public_html/generatedata-3.0.8/resources/templates/install.tpl" */ ?>
<?php /*%%SmartyHeaderCode:562246585272b3b4077cc3-43952893%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '85b0343d828c752ba61fcfbdc9a4f85df1aeddc2' => 
    array (
      0 => '/home/stu/nramsey/public_html/generatedata-3.0.8/resources/templates/install.tpl',
      1 => 1382913924,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '562246585272b3b4077cc3-43952893',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'L' => 0,
    'theme' => 0,
    'currLang' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.8',
  'unifunc' => 'content_5272b3b41402f3_05794706',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5272b3b41402f3_05794706')) {function content_5272b3b41402f3_05794706($_smarty_tpl) {?><?php if (!is_callable('smarty_function_language_dropdown')) include '/home/stu/nramsey/public_html/generatedata-3.0.8/resources/libs/smarty/plugins/function.language_dropdown.php';
?><!DOCTYPE html>
<html>
<head>
	<title><?php echo $_smarty_tpl->tpl_vars['L']->value['title'];?>
</title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="description" content="<?php echo $_smarty_tpl->tpl_vars['L']->value['meta_description'];?>
" />
	<meta name="keywords" content="<?php echo $_smarty_tpl->tpl_vars['L']->value['meta_keywords'];?>
" />
	<link rel="stylesheet" type="text/css" href="resources/themes/<?php echo $_smarty_tpl->tpl_vars['theme']->value;?>
/compiled/styles.css" />
	<link rel="stylesheet" type="text/css" href="resources/css/smoothness/jquery-ui.min.css" />
	<script src="resources/scripts/libs/jquery.min.js"></script>
	<script src="resources/scripts/libs/jquery-ui.min.js"></script>
	<script src="resources/scripts/libs/jquery.json-2.2.min.js"></script>
	<script src="resources/scripts/libs/chosen.jquery.min.js"></script>
	<script src="resources/scripts/libs/require.js" data-main="resources/scripts/install"></script>
	<script src="resources/scripts/requireConfig.js"></script>
	<!--[if lt IE 9]>
	<script src="resources/scripts/libs/html5shiv.js"></script>
	<script src="resources/scripts/libs/excanvas.js"></script>
	<![endif]-->
	<script src="resources/scripts/libs/spinners.js"></script>
</head>
<body class="gdInstallPage" data-lang="<?php echo $_smarty_tpl->tpl_vars['currLang']->value;?>
">
	<header>
		<nav>
			<?php echo smarty_function_language_dropdown(array('nameId'=>"gdSelectLanguage"),$_smarty_tpl);?>

		</nav>
	</header>
	<nav id="gdMainTabs" class="gdHideNoJS">
		<span id="gdProcessingIcon"></span>
		<ul>
			<li id="gdMainTab1" class="gdSelected"><?php echo $_smarty_tpl->tpl_vars['L']->value['install'];?>
</li>
			<li id="gdMainTab2" class="gdHideNoJS"><?php echo $_smarty_tpl->tpl_vars['L']->value['help'];?>
</li>
		</ul>
	</nav>
	<noscript><p><?php echo $_smarty_tpl->tpl_vars['L']->value['no_js'];?>
</p></noscript>
	<section class="gdHideNoJS">
		<div id="gdContent">
			<ul class="gdMainTabContent">
				<li id="gdMainTab1Content"><?php echo $_smarty_tpl->getSubTemplate ("install.tab1.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>
</li>
				<li id="gdMainTab2Content" style="display:none"><?php echo $_smarty_tpl->getSubTemplate ("install.tab2.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>
</li>
			</ul>
		</div>
	</section>
	<?php echo $_smarty_tpl->getSubTemplate ("footer.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, null, null, array(), 0);?>

</body>
</html><?php }} ?>