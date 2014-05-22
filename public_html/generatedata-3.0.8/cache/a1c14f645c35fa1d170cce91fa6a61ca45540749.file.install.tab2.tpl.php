<?php /* Smarty version Smarty-3.1.8, created on 2013-10-31 12:47:00
         compiled from "/home/stu/nramsey/public_html/generatedata-3.0.8/resources/templates/install.tab2.tpl" */ ?>
<?php /*%%SmartyHeaderCode:9753284325272b3b4211304-92460030%%*/if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    'a1c14f645c35fa1d170cce91fa6a61ca45540749' => 
    array (
      0 => '/home/stu/nramsey/public_html/generatedata-3.0.8/resources/templates/install.tab2.tpl',
      1 => 1382913924,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '9753284325272b3b4211304-92460030',
  'function' => 
  array (
  ),
  'variables' => 
  array (
    'L' => 0,
  ),
  'has_nocache_code' => false,
  'version' => 'Smarty-3.1.8',
  'unifunc' => 'content_5272b3b4226091_55664289',
),false); /*/%%SmartyHeaderCode%%*/?>
<?php if ($_valid && !is_callable('content_5272b3b4226091_55664289')) {function content_5272b3b4226091_55664289($_smarty_tpl) {?><h1><?php echo $_smarty_tpl->tpl_vars['L']->value['help'];?>
</h1>
<p>
	<?php echo $_smarty_tpl->tpl_vars['L']->value['help_intro'];?>

</p>

<h2><?php echo $_smarty_tpl->tpl_vars['L']->value['help_prerequisites'];?>
</h2>
<p>
	<?php echo $_smarty_tpl->tpl_vars['L']->value['help_prereq_info'];?>

</p>

<h2><?php echo $_smarty_tpl->tpl_vars['L']->value['still_stuck'];?>
</h2>
<p>
	<?php echo $_smarty_tpl->tpl_vars['L']->value['install_user_doc_link'];?>

</p><?php }} ?>